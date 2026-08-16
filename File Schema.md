# File Schema

The active layout uses flat topic files. The older nested `topics/` layout is deprecated.

```text
p400 Lectures/
├── AGENTS.md
├── README.md
├── _quarto.yml
├── index.html
├── inventory.csv
├── lessons.csv
├── Dictionary_of_Terms.csv
├── plantuml-filter.lua
├── styles/
│   └── styles.css
├── img/
├── p400_lecture_01.00 *** Week 1 ***/
├── p400_lecture_01.01/
│   ├── p400_lecture_01.01.qmd
│   ├── topic_1_keyword.qmd
│   ├── topic_2_keyword.qmd
│   ├── slide_catalog.csv
│   ├── images/
│   ├── cpp/
│   ├── render_only.sh
│   ├── render_only.command
│   ├── render_and_push.sh
│   ├── render_and_push.command
│   ├── p400_lecture_01.01.html
│   └── p400_lecture_01.01_files/
└── p400_lecture_01.02/ (repeats through Week 17)
```

The rendered `.html` file, its matching `_files/` directory, and `slide_catalog.csv` appear after a lecture is built. Source topic files remain directly beside the stitched lecture file.
