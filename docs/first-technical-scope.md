# Primeiro escopo técnico

## Objetivo

Este documento define o primeiro recorte técnico planejado para o RestPK: um protótipo jogável local capaz de validar os fundamentos de exploração antes da integração com o Canary.

O protótipo deverá manter apresentação, lógica local e contratos compartilhados separados. Essa divisão deverá permitir que a futura integração com o servidor substitua ou adapte a lógica local sem exigir uma reestruturação completa do cliente.

Esta sequência substitui a priorização técnica anterior que colocava o bootstrap do servidor antes do protótipo local. O Canary continua na stack planejada, mas sua integração ocorrerá em uma etapa posterior.

## Direção arquitetural inicial

A separação conceitual planejada é:

```text
RestPK
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
2. Preparar uma aplicação local mínima e compilável, após a escolha documentada da base gráfica e do sistema de build.
3. Abrir uma janela e executar um game loop básico.
4. Carregar ou gerar um mapa pequeno para validação técnica.
5. Desenhar os tiles de chão do mapa.
6. Desenhar um personagem em uma posição do mundo.
7. Movimentar o personagem por tiles, aceitando WASD e setas direcionais.
8. Validar limites do mapa e bloquear movimento em tiles não caminháveis.
9. Fazer a câmera acompanhar o personagem e exibir temporariamente sua posição para depuração.
10. Preparar os limites e contratos necessários para uma futura integração com o servidor Canary.

Cada task de implementação deverá ter um objetivo reduzido e verificável. Decisões como biblioteca gráfica, sistema de build e formato inicial do mapa deverão ser tratadas em tasks próprias, sem antecipar integrações que não sejam necessárias ao marco em andamento.

## Responsabilidades neste recorte

- `client/` deverá cuidar da janela, renderização, entrada, câmera e apresentação do estado.
- `backend/` deverá executar localmente o estado do mundo, movimento, colisão e validação das regras básicas, sem representar um servidor multiplayer.
- `shared/` deverá definir contratos independentes do sistema gráfico e do Canary.
- `map/` deverá representar o espaço jogável utilizado pelo protótipo.
- `server/` permanecerá reservado para a integração futura com o Canary.

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

Todo o conteúdo deste documento descreve trabalho planejado. Esta etapa documental não implementa a aplicação, o game loop, o mapa, a renderização, o movimento, a colisão, a câmera ou a integração com o Canary.
