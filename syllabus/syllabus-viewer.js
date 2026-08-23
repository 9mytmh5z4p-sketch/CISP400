(function () {
  "use strict";

  const SOURCE_PATH = "./p400-syllabus(LIVE).md";
  const SOURCE_NAME = "p400-syllabus(LIVE).md";
  const documentElement = document.getElementById("syllabus-document");
  const statusElement = document.getElementById("viewer-status");
  const reloadButton = document.getElementById("reload-markdown");
  const fileInput = document.getElementById("markdown-file");

  const allowedTags = new Set([
    "A", "B", "BLOCKQUOTE", "BR", "CODE", "DEL", "DETAILS", "EM",
    "H1", "H2", "H3", "H4", "H5", "H6", "HR", "I", "IMG", "KBD",
    "LI", "MARK", "OL", "P", "PRE", "S", "STRONG", "SUB", "SUMMARY",
    "SUP", "TABLE", "TBODY", "TD", "TFOOT", "TH", "THEAD", "TR", "UL"
  ]);

  const forbiddenTags = new Set([
    "BASE", "BUTTON", "CANVAS", "EMBED", "FORM", "FRAME", "FRAMESET",
    "IFRAME", "INPUT", "LINK", "MATH", "META", "NOSCRIPT", "OBJECT",
    "OPTION", "SCRIPT", "SELECT", "SOURCE", "STYLE", "SVG", "TEMPLATE",
    "TEXTAREA", "VIDEO", "AUDIO"
  ]);

  function setStatus(message) {
    statusElement.textContent = message;
  }

  function showMessage(title, paragraphs, isError) {
    documentElement.replaceChildren();
    const panel = document.createElement("section");
    panel.className = "viewer-message" + (isError ? " viewer-message--error" : "");

    const heading = document.createElement("h1");
    heading.textContent = title;
    panel.appendChild(heading);

    for (const text of paragraphs) {
      const paragraph = document.createElement("p");
      paragraph.textContent = text;
      panel.appendChild(paragraph);
    }

    documentElement.appendChild(panel);
    documentElement.setAttribute("aria-busy", "false");
  }

  function isSafeLink(value) {
    if (!value) return false;
    const candidate = value.trim();
    if (candidate.startsWith("#")) return true;
    try {
      const url = new URL(candidate, document.baseURI);
      return url.protocol === "http:" || url.protocol === "https:" || url.protocol === "mailto:";
    } catch (_error) {
      return false;
    }
  }

  function isSafeImage(value) {
    if (!value) return false;
    const candidate = value.trim();
    if (/^data:image\/(?:png|gif|jpe?g|webp);base64,/i.test(candidate)) return true;
    if (/^[a-z][a-z0-9+.-]*:/i.test(candidate) || candidate.startsWith("//")) return false;
    return !candidate.split(/[?#]/, 1)[0].split("/").includes("..");
  }

  function unwrap(element) {
    const parent = element.parentNode;
    if (!parent) return;
    while (element.firstChild) parent.insertBefore(element.firstChild, element);
    element.remove();
  }

  function sanitizeHtml(html) {
    const template = document.createElement("template");
    template.innerHTML = html;

    for (const element of Array.from(template.content.querySelectorAll("*"))) {
      const tag = element.tagName;

      if (forbiddenTags.has(tag)) {
        element.remove();
        continue;
      }

      if (!allowedTags.has(tag)) {
        unwrap(element);
        continue;
      }

      const href = tag === "A" ? element.getAttribute("href") : null;
      const src = tag === "IMG" ? element.getAttribute("src") : null;
      const alt = tag === "IMG" ? element.getAttribute("alt") : null;
      const title = element.getAttribute("title");
      const languageClass = tag === "CODE" ? element.getAttribute("class") : null;
      const listStart = tag === "OL" ? element.getAttribute("start") : null;
      const colspan = tag === "TD" || tag === "TH" ? element.getAttribute("colspan") : null;
      const rowspan = tag === "TD" || tag === "TH" ? element.getAttribute("rowspan") : null;

      for (const attribute of Array.from(element.attributes)) {
        element.removeAttribute(attribute.name);
      }

      if (tag === "A" && isSafeLink(href)) {
        element.setAttribute("href", href);
        if (!href.startsWith("#")) {
          element.setAttribute("target", "_blank");
          element.setAttribute("rel", "noopener noreferrer");
        }
      }

      if (tag === "IMG" && isSafeImage(src)) {
        element.setAttribute("src", src);
        element.setAttribute("alt", alt || "");
        element.setAttribute("decoding", "async");
      }

      if (title) element.setAttribute("title", title);

      if (tag === "CODE" && /^language-[a-z0-9_-]+$/i.test(languageClass || "")) {
        element.setAttribute("class", languageClass);
      }

      if (tag === "OL" && /^-?\d+$/.test(listStart || "")) {
        element.setAttribute("start", listStart);
      }

      if ((tag === "TD" || tag === "TH") && /^\d+$/.test(colspan || "")) {
        element.setAttribute("colspan", colspan);
      }

      if ((tag === "TD" || tag === "TH") && /^\d+$/.test(rowspan || "")) {
        element.setAttribute("rowspan", rowspan);
      }
    }

    return template.content;
  }

  function addHeadingLinks() {
    const usedIds = new Set();
    for (const heading of documentElement.querySelectorAll("h1, h2, h3, h4, h5, h6")) {
      const base = heading.textContent
        .normalize("NFKD")
        .toLowerCase()
        .replace(/[^a-z0-9]+/g, "-")
        .replace(/^-|-$/g, "") || "section";
      let id = base;
      let suffix = 2;
      while (usedIds.has(id)) id = base + "-" + suffix++;
      usedIds.add(id);
      heading.id = id;
    }
  }

  function renderMarkdown(markdown, label) {
    if (!globalThis.marked || typeof globalThis.marked.parse !== "function") {
      throw new Error("The local Markdown renderer could not be loaded.");
    }

    const html = globalThis.marked.parse(markdown, {
      gfm: true,
      breaks: false
    });

    documentElement.replaceChildren(sanitizeHtml(html));
    addHeadingLinks();
    documentElement.setAttribute("aria-busy", "false");

    const title = documentElement.querySelector("h1");
    if (title) document.title = title.textContent + " - Course Syllabus";

    setStatus("Showing " + label + ". Save your Markdown changes, then choose Reload Markdown.");
  }

  async function loadFromServer() {
    documentElement.setAttribute("aria-busy", "true");
    setStatus("Loading " + SOURCE_NAME + "...");

    try {
      const response = await fetch(SOURCE_PATH, { cache: "no-store" });
      if (!response.ok) throw new Error("HTTP " + response.status);
      renderMarkdown(await response.text(), SOURCE_NAME);
    } catch (error) {
      showMessage(
        "The Markdown file could not be loaded",
        [
          "Use preview-syllabus.command to open the local preview, or choose Open Markdown above and select " + SOURCE_NAME + ".",
          "Technical detail: " + error.message
        ],
        true
      );
      setStatus("Unable to load " + SOURCE_NAME + ".");
    }
  }

  async function loadSelectedFile(file) {
    if (!file) return;
    documentElement.setAttribute("aria-busy", "true");
    setStatus("Opening " + file.name + "...");
    try {
      renderMarkdown(await file.text(), file.name);
    } catch (error) {
      showMessage("The selected file could not be rendered", [error.message], true);
      setStatus("Unable to render " + file.name + ".");
    }
  }

  reloadButton.addEventListener("click", function () {
    if (location.protocol === "file:") {
      fileInput.click();
    } else {
      loadFromServer();
    }
  });

  fileInput.addEventListener("change", function () {
    loadSelectedFile(fileInput.files && fileInput.files[0]);
  });

  if (location.protocol === "file:") {
    showMessage(
      "Choose the Markdown syllabus",
      [
        "Browsers do not automatically read a neighboring Markdown file when an HTML file is opened directly.",
        "Choose Open Markdown above and select " + SOURCE_NAME + ", or double-click preview-syllabus.command for automatic loading and refreshes."
      ],
      false
    );
    setStatus("Direct-file mode: choose " + SOURCE_NAME + " to preview it.");
  } else {
    loadFromServer();
  }
}());
