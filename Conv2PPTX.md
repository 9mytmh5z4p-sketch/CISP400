# Conv2PPTX.md

Date: 2026-06-07

Output created:
- `p400_lecture_02.01.pptx`
- `p400_lecture_02.02/p400_lecture_02.02.pptx`

Surprises:
- The regular `quarto` launcher failed in the sandbox while checking CPU architecture with `sysctl`. Workaround: invoke Quarto's bundled Deno runner directly with `QUARTO_BIN_PATH`, `QUARTO_SHARE_PATH`, and `DENO_DOM_PLUGIN` set.
- The direct Deno runner also needs Quarto's V8 flags, especially `--v8-flags=--enable-experimental-regexp-engine,--max-old-space-size=8192,--max-heap-size=8192`; without that, Quarto 1.8.26 can fail with `Invalid flags supplied to RegExp constructor 'l'`.
- Rendering from the project root made image paths resolve incorrectly for PowerPoint. Workaround: render from a temporary project copy where the lecture folder is beside `_quarto.yml`, `styles/`, and `plantuml-filter.lua`.
- The source references `images/static_typing_strong.png`, but that file is missing from the lecture folder and the wider lecture directory. The PowerPoint work copy replaced those two image references with text so the export could complete.
- A browser screenshot-based deck would better match the HTML exactly, but local Chrome/Playwright could not launch from this sandbox. The delivered deck is the editable Quarto/Pandoc PowerPoint export, not an exact visual screenshot clone.
- The bundled LibreOffice renderer needed a writable user profile under `/private/tmp` before it could export a PDF preview. Use single-dash `-env:UserInstallation=file:///private/tmp/...`; double-dash `--env:...` is rejected by this LibreOffice build.
- LibreOffice may print fontconfig cache warnings when sandboxed because the default font cache locations are not writable, but the PDF preview can still complete successfully.

Verification:
- PPTX package opens as a valid zip with 126 slides, 3 embedded media files, and 38 note slides.
- LibreOffice exported a 126-page PDF preview from the final PPTX.
- `p400_lecture_02.02.pptx` opens as a valid zip with 100 slides, 3 embedded media files, and 8 note slides.
- LibreOffice exported a 100-page PDF preview from `p400_lecture_02.02.pptx`.
