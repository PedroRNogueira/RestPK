# RestPK

## Quick Overview
RestPK is a **Pokémon‑style game** built on top of the classic **Tibia** engine.  The project is currently focused on establishing a clean repository structure, base documentation, and tooling foundation so that core gameplay can be added in a well‑organized way.

## Current Focus
- Create a reproducible project layout.
- Provide reference documentation for future developers.
- Prepare the repo for continuous delivery (git history, branch strategy, CI‑ready configuration).

## Planned Stack
- **Server**: TFS (Tibia Server) Canary build.
- **Client**: OTClient (mehah / OpenTibiaBR).
- **Map Editor**: Remere's Map Editor.
- **Languages**: C++ (server/client), Lua (scripting).

## Repository Structure
```
├─ docs/          # docs, roadmaps, vision, setup
├─ server/        # server source, config
├─ client/        # client source, assets
├─ map/           # map data
├─ assets/        # shared game assets
├─ tools/         # helper scripts
├─ PROJECT_RULES.md
├─ README.md
└─ .gitignore
```

## Project Status
- All directories created.
- Documentation skeleton committed.
- No gameplay code yet – the first real step will be the server and client bootstrap.

## Next Steps
1. Populate `docs/setup.md` with a detailed environment checklist.
2. Begin server configuration and basic networking.
3. On a subsequent PR, add the first playable loop.

---
*This file is frequently updated to reflect the current state of the project.*
