# PowerPoint Conversion Notes — p400_lecture_02.01

Date: 2026-06-07

Output created:
- `p400_lecture_02.01.pptx`

Surprises:
- The regular `quarto` launcher failed in the sandbox while checking CPU architecture with `sysctl`. Workaround: invoke Quarto's bundled Deno runner directly with `QUARTO_BIN_PATH`, `QUARTO_SHARE_PATH`, and `DENO_DOM_PLUGIN` set.
- Rendering from the project root made image paths resolve incorrectly for PowerPoint. Workaround: render from a temporary project copy where the lecture folder is beside `_quarto.yml`, `styles/`, and `plantuml-filter.lua`.
- The source references `images/static_typing_strong.png`, but that file is missing from the lecture folder and the wider lecture directory. The PowerPoint work copy replaced those two image references with text so the export could complete.
- A browser screenshot-based deck would better match the HTML exactly, but local Chrome/Playwright could not launch from this sandbox. The delivered deck is the editable Quarto/Pandoc PowerPoint export, not an exact visual screenshot clone.
- The bundled LibreOffice renderer needed a writable user profile under `/private/tmp` before it could export a PDF preview.

Verification:
- PPTX package opens as a valid zip with 126 slides, 3 embedded media files, and 38 note slides.
- LibreOffice exported a 126-page PDF preview from the final PPTX.
