# Topics — p400_lecture_14.02

| Topic | Emphasis | Time Budget | Optional | Prerequisites | Tone Flag | Note |
|-------|----------|-------------|----------|---------------|-----------|------|
| Review: new and delete | standard | 10 | no | 14.01 | Students have seen this in 14.01 — treat as a fast warm-up, not a re-teach. | Scalar and array forms. Key rules: new/new[] matched with delete/delete[]. File: 14-02a.cpp. |
| Pseudodynamic arrays | standard | 10 | no | Review: new and delete | | Array size fixed at compile time via a constant — not truly resizable. File: 14-02b.cpp. Transition: "a step closer, but not there yet." |
| Dynamic arrays | high | 20 | no | Pseudodynamic arrays | This is the core new concept — slow down here. | True resize via temp pointer: adjust size → new temp → copy → delete[] old → swing pointer → nullptr. Files: 14-02c.cpp. Includes two interactive visualizations (increase and decrease). |
| Programming activity | standard | 15 | no | Dynamic arrays | | Students implement a resizable short* pet ages array from scratch. File: 14-02d.cpp. Solution slide is hidden by default (data-visibility="hidden"). |

---

## Field Guide

| Field | Notes |
|-------|-------|
| **Topic** | Name of the topic to cover |
| **Emphasis** | Leave blank for standard depth. Note if extra depth is needed, e.g. "students struggle with this" |
| **Time Budget** | Rough target in minutes, e.g. "10 min". Leave blank to let content dictate |
| **Optional** | Yes = cut if running short. Leave blank = required |
| **Prerequisites** | Topic or lecture number students need to have seen first. Leave blank if none |
| **Tone Flag** | Any framing notes, e.g. "students find this intimidating — be encouraging" |
| **Note** | Notes to myself regarding this topic. |