# RestPK

## Visão geral

RestPK é um projeto de jogo inspirado em Tibia com temática Pokémon. A stack final planejada continua baseada no ecossistema OpenTibia, mas o foco técnico atual é preparar um protótipo jogável local antes da integração com o Canary.

## Estado atual do projeto

O projeto está em uma etapa documental e estrutural. O protótipo local e o gameplay ainda não foram implementados, e o Canary e o OTClient ainda não foram importados.

A direção inicial separa três responsabilidades:

- `client/`: apresentação visual, janela, entrada do teclado e câmera;
- `backend/`: lógica local, estado do mundo, movimento e colisões;
- `shared/`: contratos e estruturas independentes da renderização e do Canary.

Essa separação deve permitir que a lógica inicial seja executada localmente e que, em uma etapa posterior, o Canary substitua ou adapte essa camada sem exigir uma reestruturação completa do cliente e dos contratos compartilhados.

## Primeiro objetivo jogável

O primeiro marco técnico será uma aplicação local capaz de abrir uma janela e executar um game loop, apresentar um mapa pequeno com tiles de chão e um personagem, permitir movimento por tiles com WASD e setas direcionais, bloquear tiles não caminháveis, acompanhar o jogador com uma câmera e exibir temporariamente sua posição para depuração.

Esse marco será construído em tasks pequenas. Sistemas de gameplay avançado, conteúdo definitivo, multiplayer e comunicação de rede permanecem fora desse primeiro recorte.

## Stack planejada

- **Servidor futuro**: Canary;
- **Cliente futuro**: OTClient mehah / OpenTibiaBR;
- **Editor de mapa**: Remere's Map Editor;
- **Linguagens principais**: C++ e Lua.

A integração do Canary fica adiada até que os fundamentos do protótipo jogável local tenham sido validados.

## Estrutura do repositório

```text
├─ client/            # apresentação e entrada do protótipo
├─ backend/           # lógica local independente da renderização
├─ shared/            # contratos e estruturas independentes
├─ server/            # espaço reservado para a futura integração do Canary
├─ map/               # arquivos relacionados a mapas
├─ assets/            # recursos visuais e auxiliares
├─ tools/             # scripts e utilitários auxiliares
├─ docs/              # documentação do projeto
├─ AGENT_RULES.md     # regras permanentes do agente
├─ PROJECT_RULES.md   # regras resumidas do projeto
├─ README.md
└─ .gitignore
```
