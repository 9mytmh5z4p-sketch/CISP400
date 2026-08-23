# p400 Lectures — Codex Project Context

## How to Start a Build Session

Tell Codex: **"Build lecture p400_lecture_XX.YY"**

Codex will:
1. Read `lessons.csv` and `inventory.csv` from this folder (`p400 Lectures/`)
2. Use the topics supplied by the instructor in the build request
3. Read `planning_notes.md` from the working lecture subfolder if it exists
4. Check the working subfolder for any PDF files of prior slides — if found, use them to match voice, phrasing, and slide structure; if not, rely on `lessons.csv` and flag the absence
5. Proceed with topic ordering, topic-by-topic slide proposals, and generation only after instructor approval

**Deprecated planning files:** All `topics.md` files are deprecated and are no longer used. Do not read, create, update, or rely on them during lecture planning or generation.

**Scope:** Read `lessons.csv` from the parent folder. Read and write `inventory.csv` in the parent folder for topic tracking. Read and write only within the specified working subfolder otherwise. Do not touch any other folder.

**Rendering:** Do not attempt to render lectures or run render scripts. The instructor will handle rendering.

**Rendered HTML:** When not rendering, do not update generated `.html` lecture files. Update only source files such as `.qmd`; the instructor will render and replace HTML output.

---

## Project Structure

Each lecture lives in its own flat subfolder. All files sit at the same level — no `topics/` subfolder.

```
p400_lecture_XX.YY/
  p400_lecture_XX.YY.qmd   ← stitched lecture (main render target)
  topic_1_keyword.qmd       ← one file per topic, flat alongside main
  topic_2_keyword.qmd
  ...
  images/                   ← images referenced in slides
  cpp/                      ← standalone .cpp example files
  render_only.sh / .command
  render_and_push.sh / .command
```

Shared project files at `p400 Lectures/` root — do not copy or modify per-lecture:
- `_quarto.yml` — shared Quarto format, filters, engine settings
- `styles/styles.css` — shared CSS
- `plantuml-filter.lua` — centralized Lua filter (referenced by `_quarto.yml`)
- `inventory.csv` — append-only topic tracking across all lectures
- `Dictionary_of_Terms.csv` — shared slide-category terms and definitions
- `lessons.csv` — session lessons, added with instructor approval

---

## Filename Convention

- `0x` = zero-padded week number (e.g., `09`)
- `0y` = lecture number within the week, always `01` or `02`
- Example: `p400_lecture_09.01` = Week 9, first lecture

---

## Topic Ordering

1. Use the topics supplied by the instructor. Suggest an ordering and briefly explain the rationale.
2. Flag any topics that are missing, should be split, or overlap with prior lectures (check `inventory.csv`).
3. Wait for instructor approval before generating anything.

Ask clarifying questions **one at a time** and wait for each answer before asking the next. Stop when you have enough to proceed.

---

## Topic Slide Proposal

After the instructor approves the topic order, propose slides **one topic at a time** before creating any `.qmd` files.

For each topic:
1. Provide a sentence description of the topic's purpose and teaching angle.
2. List the proposed slides for that topic in order, using short slide titles and one sentence describing what each slide will cover.
3. Identify pedagogical-marker slides directly in the proposal by adding `[Marker: Name]` after the slide title. If one slide serves multiple marker functions, list each one. Do not label ordinary content slides.
4. Include the topic's planning markers in the proposal and explain whether each one becomes a slide, is incorporated into another slide, or does not warrant slide space.
5. Wait for instructor feedback or approval before moving to the next topic.
6. Revise the proposal if requested and wait again.

Do not generate topic files, stitched lecture files, appendix slides, inventory updates, or rendered output until the instructor has approved the slide proposal for every topic.

## Pedagogical Markers

Pedagogical markers are instructional functions that help students organize, understand, apply, and retain a topic. They are planning labels, not text that must appear visibly on the rendered slide. Use only the markers that genuinely serve the topic; do not force every topic into the same sequence or create a separate slide for every marker.

1. **Value Added** — Explain how the topic improves the student's ability to design or write programs.
2. **Connect** — Link the topic to knowledge students already possess.
3. **Define** — State the topic's essential meaning and vocabulary.
4. **Enumerate** — List the topic's major components, forms, or operations without commentary so students can see the complete territory before examining its parts.
5. **Anatomy** — Label the parts of representative syntax, a diagram, or a process.
6. **Model** — Provide a mental or visual representation of how the topic works.
7. **Predict** — Ask students to anticipate an effect, state change, or output before revealing it.
8. **Trace** — Follow program state or execution through a sequence.
9. **Invariant** — Identify a condition that must remain true throughout an operation.
10. **Boundary** — Establish valid limits and examine behavior at their edges.
11. **Before/After** — Compare program state immediately before and after an operation.
12. **Contrast** — Distinguish the topic from a similar or easily confused concept.
13. **Demonstrate** — Show the concept operating in a focused example.
14. **Compose** — Combine individual components into a complete program or algorithm.
15. **Decision Point** — Explain when to use the topic and when another approach is preferable.
16. **Transfer** — Apply the same idea in a meaningfully different programming situation.
17. **Summarize** — Close the topic with its two or three essential ideas in no more than two or three sentences.

Use **Summarize** sparingly. The required final summary slide normally satisfies this marker. Do not add interim recap or summary slides unless the instructor requests them or the topic has an unusually long sequence whose complexity clearly justifies one. Repeated summaries slow the lecture and should not become a default rhythm.

### Planning Markers

Planning markers shape the proposal but do not automatically require their own slides.

18. **Prerequisite Check** — Identify the knowledge students need before the topic and determine whether it needs a brief review, can be assumed, or reveals a prerequisite gap that must be raised with the instructor.
19. **Progression Map** — Show where the topic sits in the larger learning sequence and how it prepares students for what follows.

For every initial topic slide proposal, explicitly report the **Prerequisite Check** and **Progression Map** decisions. Also identify every proposed slide that serves one or more of markers 1–17. Marker labels may be removed when generating the `.qmd`; their purpose is to make the instructional design visible during proposal and approval.

---

## File Generation

For each approved topic, generate a separate `.qmd` file:
- **Filename:** `topic_x_keyword_keyword.qmd` — `x` is the topic number; keywords are 2–3 words from the topic name joined by underscores (e.g., `topic_1_for_loop.qmd`, `topic_2_global_variables.qmd`)
- **Location:** working subfolder root (flat, alongside the main lecture file)

After all topic files are generated, stitch them into a main lecture file:
- **Filename:** `p400_lecture_0x.0y.qmd`
- **Location:** working subfolder root
- The stitched file has **no slide count**

After the instructor has approved all topic slide proposals and the lecture source files have been generated, create a slide catalog CSV file:
- **Filename:** `slide_catalog.csv`
- **Location:** working lecture subfolder root
- **One row per slide:** Include every slide with a visible slide number, including Last Time, Today's Agenda, topic section dividers, Key Takeaways, Next Time, Appendix, and appendix slides.
- **Columns, in this exact order:** `Slide Number, Topic, Subject, Title, Category, Filename`
- **Slide Number:** Use the global slide number that displays for the slide and matches the `<!-- Slide N -->` marker.
- **Topic:** Use the lecture topic or structural area the slide belongs to, such as `Course Framing`, the topic name, `Course Wrap-Up`, or `Appendix`.
- **Subject:** Use the exact matching value from the `Subject` column in `inventory.csv` when the slide belongs to an instructional topic. Leave this blank for framing, wrap-up, and appendix-divider slides that do not map cleanly to one inventory subject.
- **Title:** Use the slide's `#` or `##` heading. If a slide has no title, create a temporary descriptive title and wrap it in angle brackets, such as `<Opening Context>`.
- **Category:** Assign one instructional category term from `Dictionary_of_Terms.csv`. If no existing category term fits, ask the instructor before adding a new term to the dictionary.
- **Filename:** List the file name for any asset or image used by that slide. Leave this blank when the slide does not use an asset or image. If a slide uses multiple files, separate the filenames with spaces or semicolons, not commas.
- **CSV safety:** Do not use commas inside unquoted fields. Prefer category definitions and generated titles without commas.

---

## C++ Code Style

All running code examples use the following style:

- `using namespace std;` — always present; never prefix standard library names with `std::`
- Function prototypes — declare all functions above `main`; define them below
- Inline comments — plain English, no dot-padding (`//..........`), no step numbers

## Slide Rules

- Use **Quarto Markdown** with Reveal.js slide syntax (`---` as slide separator)
- Use only `#` (h1) and `##` (h2) headers
- Tone: professional, concise, direct. No emojis.
- No filler phrases. Say what needs to be said and stop.
- Lists: no more than two sentences per item
- Text per slide: no more than three short paragraphs
- Title slides must use Title Case unless the title includes C++ syntax that should preserve its exact spelling or capitalization.
- In a two-column slide with code only in the left column, reduce the code font size by 50% from the normal code size.
- Do **not** put programming exercises or common mistakes in the main slide content
- If you have a best practices slide, title it **"Common Practices"**
- Let content dictate slide count — don't pad and don't compress. Use any emphasis or time guidance supplied directly by the instructor to calibrate depth.

**Last Time slide (stitched file):**
- List only the bold topic names — no explanatory text after the em-dash.
- Correct: `+ **Variables and Assignment**`
- Wrong: `+ **Variables and Assignment** — declaration reserves memory; initialization fills it.`
- Do **not** place a `---` separator between `# Last Time` and `# Today's Agenda` — two consecutive `#` headings without a separator is correct; a `---` between them creates a blank slide.
- Do **not** place a `---` separator between a `#` (h1) heading and the first `##` (h2) slide that follows it — the `##` already creates a new slide; a `---` between them creates a blank intermediate slide. The `# Topic Name` in a topic file should be followed directly by `## First slide`, not `---` then `## First slide`.

**Slide numbering — global (matches the Reveal.js counter):**
- `<!-- Slide N -->` comments use **global** slide numbers that match what appears on screen, not local topic numbers.
- Numbering starts in the stitched `.qmd` file: `# Last Time` = Slide 1, `# Today's Agenda` = Slide 2.
- Each topic file contributes: one slide for the `# Topic Name` section header, then one per `##` content slide.
- The topic file header should read `<!-- Slides X–Y -->` showing the global range for that topic.
- The speaker notes on the first `##` slide should read `Slides X–Y` (global range).
- The `# Topic Name` heading in each topic file gets its own `<!-- Slide N -->` marker immediately after it.
- When building a new lecture, compute global offsets before writing any topic file: count Last Time (1) + Today's Agenda (1) + each prior topic's section header (1) + content slides, then continue from there.

**Per topic file:**
- First slide: one introductory slide — preferably a question the section will answer. Max 3 sentences.
  - Speaker notes on first slide: global range, e.g. `Slides 4–19`
- Last slide: a brief summary of the key point. Max 2 sentences.
- Where a drawing or graphic would help, note it in speaker notes only:
  ```
  ::: notes
  [Graphic suggestion: describe what would go here]
  :::
  ```
- Speaker notes (`:::notes ... :::`) go at the bottom of the slide, after all content and before the `<!-- Slide N -->` comment.
- At the bottom of each slide, add an HTML comment with the **global** slide number:
  ```
  <!-- Slide 14 -->
  ```

---

## Appendix

The appendix lives in the **stitched lecture file**, not in individual topic files. After `# Next Time`, add one sub-section per topic. Each sub-section gets its own set of slides covering:
- Good Practices
- Common Mistakes
- More Examples
- Practice Problems
- AI Search Terms
- Questions for Reflection

---

## Topic File Template

```markdown
<!-- Topic N: Topic Name Here -->
<!-- Slides X–Y -->

# Topic Name Here
<!-- Slide X-1 -->

## Opening Question or Title {.smaller}

Brief intro — preferably a question the section will answer. Max 3 sentences.

::: notes
Slides X–Y
:::

<!-- Slide X -->

---

## Slide Title

Content here.

<!-- Slide X+1 -->

---

## Summary

One or two sentences capturing the key takeaway.

<!-- Slide N -->
```

---

## Stitched Lecture Front Matter

The main `p400_lecture_0x.0y.qmd` has no YAML frontmatter — all settings come from `_quarto.yml`. Version tracking is maintained in `_quarto.yml`, not in individual lecture files.

```markdown
# Last Time

::: {.incremental}
+ **Topic 1**
+ **Topic 2**
+ **Topic 3**
:::

::: notes
[Brief recall notes]
:::

# Today's Agenda

- Topic 1
- Topic 2
- ...

::: notes

:::

{{< include topic_1_keyword.qmd >}}
{{< include topic_2_keyword.qmd >}}
...

---

# Key Takeaways

- Takeaway 1
- Takeaway 2

---

# Next Time

---

# Appendix

---

## [Topic 1 Name]: Good Practices

---

## [Topic 1 Name]: Common Mistakes

---

## [Topic 1 Name]: More Examples

---

## [Topic 1 Name]: Practice Problems

---

## [Topic 1 Name]: AI Search Terms

---

## [Topic 1 Name]: Questions for Reflection

---

## [Topic 2 Name]: Good Practices

<!-- repeat pattern for each topic -->
```

The agenda should list only instructional topics being discussed. Do **not** include exercises, labs, coding activities, review games, or other activities on the agenda slide, even if those activities appear later in the lecture.

---

## CriticGPT Review

After generating all topic files:
1. Create `critic.md` in the working subfolder
2. Have CriticGPT review all topic files and write structured feedback in `critic.md`
3. Discuss the feedback with the instructor. Update topic files if warranted.
4. Do not ask the instructor before proceeding with the review — run it automatically.
5. **Delete `critic.md` when the review is complete and no further changes are needed.**

**CriticGPT must check for blank slides.** A blank slide is created when two `---` separators have only HTML comments between them (comments are invisible to Reveal.js, leaving an empty slide). The topic file template avoids this by placing HTML comments at the top of the `#` section rather than between separators. Flag any file where `---` appears immediately before or after a block of HTML comment lines with no real content between them.

---

## Post-Generation: Update index.html

Update `index.html` in this folder to reflect the completed lecture.

- Find the `.lec-pane` card whose link `href` matches the lecture just built (e.g., `p400_lecture_09.01/p400_lecture_09.01.html`).
- Update that card's `.lec-title` link text with a short title derived from the lecture content.
- Keep the existing `.lec-badge`, `.lec-slot`, week card, and section structure intact.
- If no card exists for the lecture, add one in the correct `.week-card`, following the existing `.lec-pane` pattern.
- If a new week or course section is required, ask the instructor for its title before adding it.
- Do **not** change any other entries

---

## Post-Generation: Update inventory.csv

Append one row per topic to `inventory.csv` in this folder. Do not overwrite existing rows.

```
lecture, week, section, Subject, emphasis, time_budget, optional, notes
```

---

## Post-Generation: Update lessons.csv

Propose additions **one at a time** and wait for instructor approval before writing anything.

```
date, lecture, category, lesson, applied
```

Categories: *voice*, *structure*, *slide length*, *Quarto syntax*, *tone*, *emphasis*, *pacing*
`applied` = whether this lesson has been used in a subsequent lecture (default: `no`)

---

## Output Summary

| File | Location |
|------|----------|
| `topic_x_keyword.qmd` (one per topic) | `[working subfolder]/` |
| `p400_lecture_0x.0y.qmd` (stitched) | `[working subfolder]/` |
| `slide_catalog.csv` | `[working subfolder]/` |
| `index.html` (update link text) | `p400 Lectures/` |
| `inventory.csv` (append only) | `p400 Lectures/` |
| `Dictionary_of_Terms.csv` | `p400 Lectures/` |
| `lessons.csv` (with approval) | `p400 Lectures/` |
