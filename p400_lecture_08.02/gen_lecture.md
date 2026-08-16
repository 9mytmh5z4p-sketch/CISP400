---
id: lecture_generation_prompt
version: 0.1
status: draft        # draft | stable | deprecated
category: content_creation  
intended_use: instruction
schema: htmll lecture for Quarto    # Output blueprint
ensemble_compatible: true
created: 2026-03-7
last_modified: 2026-03-7
# I need to copy the template and rename it for the lecture.
# Copy this file there, too. However Promptorium is authoratative.
---
# Lecture Generation Prompt — p400

## Context & Setup

You are generating Quarto Markdown lecture content for a college-level introductory C++ course (p400). The instructor's style is **concise and direct** — no filler, no padding, no fluff.

Before doing anything else:
1. Read `lessons.csv` and `inventory.csv` from the parent `p400 Lectures/` folder. Apply any relevant lessons to your work.
2. Check the working subfolder for any PDF files of prior slides. If present, use them to match the instructor's voice, phrasing, and slide structure. If absent, rely on `lessons.csv` for style guidance and flag that no PDF was found.
3. Read `topics.md` from the working subfolder. This is your source of truth for what to cover.
4. The working subfolder for this session is: **[INSTRUCTOR SPECIFIES THIS]**.
   - You may read `lessons.csv` and `inventory.csv` from the parent `p400 Lectures/` folder.
   - Rename "Lecture Template.qmd" to INSTRUCTOR SPECIFIED SUBFOLDER NAME.qmd
    - Do not modify any YAML in this template file.
   - You may read and write only within the specified working subfolder.
   - **Do not touch any other folder under any circumstances.**

---

## Filename Convention

- `0x` = week number (e.g., `08`)
- `0y` = lecture number within the week — always `01` or `02`
- Example: `p400_lecture_08.01` = Week 8, first lecture

---

## topics.md Format

The instructor provides a Markdown table in `topics.md`:

```markdown
| topic | emphasis | time_budget | optional | notes |
|-------|----------|-------------|----------|-------|
| Global Variables | high | 10 | no | Students confuse scope with lifetime |
| Local Variables | medium | 8 | no | |
| Static Local Variables | low | 5 | yes | |
```

- `emphasis`: high / medium / low — drives slide depth and count
- `time_budget`: target teaching time in minutes
- `optional`: topics to cut if running short
- `notes`: instructor guidance that shapes framing and depth

---

## Before You Start

Ask clarifying questions **one at a time** and wait for each answer before asking the next. Stop when you have enough to proceed.

---

## Topic Ordering

1. Read `topics.md` and suggest an ordering. Briefly explain your rationale.
2. Flag any topics you think are missing, should be split, or overlap with prior lectures (check `inventory.csv`).
3. Wait for approval before generating anything.

---

## File Generation

For each approved topic, generate a separate file:
- **Filename:** `topic_x_keyword_keyword.qmd` where `x` is the topic number and the keywords are 2-3 words from the topic name, joined by underscores (e.g., `topic_1_for_loop.qmd`, `topic_2_global_variables.qmd`)
- **Location:** `p400 Lectures/[working subfolder]/topics/`

After all topic files are generated, stitch them into:
- **Filename:** `p400_lecture_0x.0y.qmd`
- **Location:** `p400 Lectures/[working subfolder]/`
- The stitched file has **no slide count**.

---

## Slide Rules

- Use **Quarto Markdown** with Reveal.js slide syntax (`---` as slide separator).
- Use only `#` (h1) and `##` (h2) headers.
- Tone: professional, concise, direct. No emojis.
- No filler phrases. Say what needs to be said and stop.
- Lists: no more than two sentences per item.
- Text per slide: no more than three short paragraphs.
- Do **not** put programming exercises or common mistakes in the main slide content.
- If you have a best practices slide, title it **"Common Practices"**.
- Let content dictate slide count — don't pad, don't compress artificially. Use `emphasis` and `time_budget` from `topics.md` to calibrate depth.

**Per topic file:**
- First slide: one introductory slide — preferably a question the section will answer. Max 3 sentences.
  - Speaker notes on first slide: total slide count for this topic (not counting appendix).
- Last slide: a brief summary of the key point. Max 2 sentences.
- Where a drawing or graphic would help, note it in speaker notes only:
  ```
  ::: notes
  [Graphic suggestion: describe what would go here]
  :::
  ```
- At the bottom of each slide, add an HTML comment with the slide number:
  ```
  <!-- Slide 3 -->
  ```

---

## Appendix

After the main slides in each topic file, add a `## Appendix` slide, followed by slides on:
- Good Practices
- Common Mistakes
- More Examples
- Practice Problems
- AI Search Terms
- Questions for Reflection

Appendix slides do **not** count toward the slide count on the first slide.

---

## CriticGPT Review

After generating all topic files:
1. Create `critic.md` in the working subfolder.
2. Have CriticGPT review the topic files and write feedback in `critic.md`.
3. Discuss the feedback. If warranted, update the topic files.
4. Do not ask the instructor before proceeding with the review.

---

## Post-Generation: Update inventory.csv

After the lecture is finalized, append new rows to `inventory.csv` in the parent folder — one row per topic:

```
lecture, week, section, topic, emphasis, time_budget, optional, notes
```

Do not overwrite existing rows. Only append.

---

## Post-Generation: Update lessons.csv

After the session, propose any additions to `lessons.csv` in the parent folder. Present each proposed addition **one at a time** and wait for approval before writing anything.

Columns:
```
date, lecture, category, lesson, applied
```

Where `category` covers: *voice*, *structure*, *slide length*, *Quarto syntax*, *tone*, *emphasis*, *pacing*, etc.  
`applied` = whether this lesson has been used in a subsequent lecture (default: `no`).

---

## Output Summary

| File | Location |
|------|----------|
| `topic_x_content.qmd` (one per topic) | `[working subfolder]/topics/` |
| `p400_lecture_0x.0y.qmd` (stitched) | `[working subfolder]/` |
| `topics.md` | `[working subfolder]/` |
| `inventory.csv` (append only) | `p400 Lectures/` (parent) |
| `lessons.csv` (with approval) | `p400 Lectures/` (parent) |