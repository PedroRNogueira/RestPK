# Primeiro escopo técnico

## Objetivo

Este documento define o primeiro recorte técnico planejado para o RestPK: um protótipo jogável local capaz de validar os fundamentos de exploração antes da integração com o Canary.

O protótipo deverá manter apresentação, lógica local e contratos compartilhados separados. Essa divisão deverá permitir que a futura integração com o servidor substitua ou adapte a lógica local sem exigir uma reestruturação completa do cliente.

Esta sequência substitui a priorização técnica anterior que colocava o bootstrap do servidor antes do protótipo local. O Canary continua reservado para uma integração futura, após a validação do protótipo.

## Stack oficial deste recorte

O protótipo adotará oficialmente:

- C++20 como linguagem, por oferecer recursos modernos em um padrão estável para a base nativa;
- MSVC 2022 x64 como compilador principal, para manter um ambiente de desenvolvimento e validação consistente no Windows;
- SDL3 como base gráfica do cliente, cobrindo janela, eventos, input e renderização;
- CMake como sistema de build, para uma descrição declarativa e evolutiva do projeto;
- `CMakePresets.json` como configuração de build, para presets reproduzíveis;
- vcpkg em Manifest Mode como gerenciador de dependências, para declarar dependências versionáveis em `vcpkg.json`.

Essas escolhas são decisões oficiais, embora os respectivos arquivos, dependências e implementações ainda não façam parte desta etapa documental.

## Direção arquitetural inicial

A separação conceitual planejada é:

```text
RestPK
├─ CMakeLists.txt
├─ CMakePresets.json
├─ vcpkg.json
├─ client/
│  ├─ engine/
│  ├─ game/
│  ├─ assets/
│  └─ main
│
├─ backend/
│  ├─ world/
│  ├─ movement/
│  ├─ collision/
│  └─ game_state/
│
├─ shared/
│  ├─ position/
│  ├─ direction/
│  ├─ tile/
│  ├─ creature/
│  └─ movement/
│
├─ server/
├─ map/
├─ assets/
├─ tools/
└─ docs/
```

Essa árvore é somente uma direção inicial. As subpastas conceituais não existem ainda e deverão ser criadas apenas quando uma task de implementação justificar sua necessidade.

## Escopo técnico inicial

O trabalho deverá avançar, em tasks pequenas, pelos seguintes itens:

1. Definir a arquitetura mínima do protótipo, separando cliente, backend local e contratos compartilhados.
2. Preparar uma aplicação local mínima e compilável com C++20, SDL3, CMake, `CMakePresets.json` e vcpkg em Manifest Mode.
3. Abrir uma janela e executar um game loop básico.
4. Carregar ou gerar um mapa pequeno para validação técnica.
5. Desenhar os tiles de chão do mapa.
6. Desenhar um personagem em uma posição do mundo.
7. Movimentar o personagem por tiles, aceitando WASD e setas direcionais.
8. Validar limites do mapa e bloquear movimento em tiles não caminháveis.
9. Fazer a câmera acompanhar o personagem e exibir temporariamente sua posição para depuração.
10. Preparar os limites e contratos necessários para uma futura integração com o servidor Canary.

Cada task de implementação deverá ter um objetivo reduzido e verificável, sem antecipar integrações que não sejam necessárias ao marco em andamento. A implementação da stack oficial deverá ocorrer em tasks próprias posteriores.

## Responsabilidades neste recorte

- `client/` deverá cuidar da janela, renderização, input, câmera e apresentação do estado.
- `backend/` deverá executar localmente as regras, o estado do mundo, o movimento e a colisão, sem representar um servidor multiplayer.
- `shared/` deverá definir `Position`, `Direction`, `Tile` e outros contratos compartilhados.
- `map/` deverá representar o espaço jogável utilizado pelo protótipo.
- `server/` permanecerá reservado para a integração futura com o Canary.

`backend/` e `shared/` não deverão depender da SDL3. Conceitos de janela, input, câmera, renderização e coordenadas de tela pertencem ao `client/`.

## Coordenadas e tiles

- O espaço do mundo (`World`) utiliza `x`, `y` e `z`.
- O espaço de tela (`Screen`) é calculado somente pelo `client/` e não integra os contratos do backend.
- O tile visual inicial terá `32x32` pixels.

O tamanho em pixels é uma decisão de apresentação e não altera a representação lógica de posições por tile no mundo.

## Movimento inicial

O primeiro movimento será restrito a quatro direções, com deslocamento de um tile por comando. Não haverá movimento diagonal, animação, autowalk ou pathfinding neste recorte.

## Game loop planejado

O loop básico seguirá esta ordem:

```text
processEvents()
update()
render()
```

- `processEvents()` coleta eventos da janela e traduz o input do usuário em comandos.
- `update()` aplica regras, movimento, colisões e demais mudanças no estado do mundo.
- `render()` converte o estado em apresentação visual e desenha o frame pelo cliente.

## Fora do primeiro marco

Não fazem parte deste recorte:

- Pokémon, captura e batalha;
- NPCs e quests;
- inventário, equipamentos e habilidades;
- login, contas e banco de dados;
- multiplayer e comunicação de rede;
- integração com o Canary;
- integração completa com o OTClient;
- mapa definitivo;
- interface e assets finais;
- sistemas avançados de gameplay.

## Resultado esperado

Quando este escopo for implementado, deverá ser possível iniciar uma aplicação local, visualizar um mapa com chão e personagem, movimentar o personagem com colisões básicas e acompanhar sua posição com a câmera.

Esse resultado deverá validar somente a base técnica do jogo. Ele não representará a arquitetura multiplayer definitiva nem a conclusão dos sistemas de gameplay.

## Estado atual

Todo o conteúdo deste documento descreve trabalho planejado sobre uma stack já decidida. Esta etapa documental não cria projeto CMake ou presets, não instala dependências, não adiciona SDL3 e não implementa C++, aplicação, game loop, mapa, renderização, movimento, colisão, câmera ou integração com o Canary.
