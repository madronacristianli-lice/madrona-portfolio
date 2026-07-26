# Cristian li G. Madrona – Academic Portfolio

A modern, clean, and interactive single-page academic portfolio built with plain HTML5, Tailwind CSS CDN, and Lucide Icons.

## How to Use

1. Open `index.html` in your web browser.
2. To edit the content, open `index.html` in a text editor (VS Code, Notepad++, etc.).

## What You Can Edit

### Hero Section
- Full name, program/year, academic year, and bio tagline are in the `<section id="home">` area.

### Subjects & Projects
- Subject data is located inside the `<script>` tag near the bottom, inside the `subjects` array.
- Each subject has:
  - `title`: Subject name
  - `semester`: `"1st"` or `"2nd"`
  - `icon`: Lucide icon name (e.g., `shield-check`, `database`, `code-2`)
  - `tags`: List of topic tags
  - `badge`: Main category badge (e.g., Cybersecurity, UI/UX, Analytics)
  - `description`: Short card description
  - `details`: Longer description shown in the modal
  - `stack`: Technologies/tools used

### Skills
- Edit the skill pills inside the `<section id="skills">` area.

### Contact / Socials
- Replace placeholder email and social links in the `<section id="contact">` area.

### Images
- Replace screenshot placeholder `<div>` elements with actual `<img>` tags when ready.

## Features

- Responsive design (mobile, tablet, desktop)
- Dark / light mode toggle
- Search and filter subjects by semester
- Modal popup for project details
- Smooth scroll navigation
- Lucide icons throughout

## No Build Required

This is a static HTML file. No npm install, no build step. Just open the file in any browser.
