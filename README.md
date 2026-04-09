# RestPK

## Visão geral
RestPK é um projeto de jogo inspirado na base do Tibia com temática de Pokémon.  
O foco atual do projeto é organizar a fundação técnica e documental, para que a evolução futura aconteça de forma controlada e consistente.

## Estado atual do projeto
No momento, o projeto está concentrado em:
- estruturar corretamente o repositório
- alinhar a documentação principal
- definir regras permanentes para trabalho com agente
- preparar a base para o futuro bootstrap técnico da stack OT

Ainda não há implementação de gameplay.

## Stack planejada
- **Servidor**: Canary
- **Cliente**: OTClient mehah / OpenTibiaBR
- **Editor de mapa**: Remere's Map Editor
- **Linguagens principais**: C++ e Lua

## Estrutura atual do repositório
```text
├─ docs/              # documentação do projeto
├─ server/            # base futura do servidor
├─ client/            # base futura do cliente
├─ map/               # arquivos relacionados ao mapa
├─ assets/            # recursos do projeto
├─ tools/             # scripts e utilitários auxiliares
├─ AGENT_RULES.md     # regras permanentes do agente
├─ PROJECT_RULES.md   # regras resumidas do projeto
├─ README.md
└─ .gitignore
