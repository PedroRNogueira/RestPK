# Arquitetura de renderização

## Objetivo

Este documento registra a arquitetura planejada para renderização, coordenadas, movimento e game loop do protótipo jogável local do RestPK. Todo o conteúdo descreve decisões de projeto; não representa código ou funcionalidade já implementada.

## Divisão de responsabilidades

### Client

O `client/` será a camada de apresentação. Ele deverá:

- criar e manter a janela com SDL3;
- capturar o input do jogador;
- controlar a câmera;
- converter coordenadas do mundo em coordenadas de tela;
- renderizar mapa, entidades e demais elementos visuais.

O cliente poderá transformar o input em comandos de movimento, mas não será responsável por validar regras do mundo ou colisões.

### Backend

O `backend/` será responsável pela lógica local do protótipo. Ele deverá:

- manter o estado do mundo;
- validar limites e colisões;
- processar comandos de movimento;
- atualizar posições e demais regras do mundo.

O backend não deverá renderizar, controlar a janela ou depender da SDL3.

### Shared

O `shared/` deverá reunir contratos independentes da apresentação, incluindo os conceitos de `Position`, `Direction` e `Tile`. Esses contratos permitirão a troca de dados entre cliente e backend sem incorporar detalhes gráficos.

O shared não deverá depender da SDL3 nem de tipos específicos da renderização.

### Server

O `server/` permanecerá reservado para a futura integração do Canary. Ele não fará parte do game loop local inicial e não será necessário para validar o primeiro protótipo jogável.

## Sistemas de coordenadas

### World

As posições no mundo serão representadas pelos eixos:

- `x`: posição horizontal em tiles;
- `y`: posição vertical em tiles;
- `z`: andar ou nível do mundo.

As coordenadas de mundo deverão pertencer aos contratos e à lógica do jogo, sem depender de pixels ou da SDL3.

### Screen

As coordenadas de tela serão calculadas exclusivamente pelo `client/`. A conversão deverá considerar a posição no mundo, a câmera e o tamanho visual do tile, sem transferir essa responsabilidade ao backend ou ao shared.

O tamanho inicial planejado para cada tile será de **32 × 32 pixels**. Essa medida será uma decisão inicial de apresentação e não alterará o significado das coordenadas do mundo.

## Movimento inicial

O primeiro modelo de movimento será limitado a:

- quatro direções;
- um tile por comando;
- sem movimento diagonal;
- sem animação de deslocamento;
- sem autowalk;
- sem pathfinding.

O cliente deverá capturar a intenção do jogador e solicitar o movimento. O backend deverá validar o comando e atualizar a posição no mundo quando o deslocamento for permitido. A renderização deverá apenas apresentar o estado resultante.

## Game loop planejado

O game loop local seguirá três etapas, executadas nesta ordem:

1. `processEvents()`: receber eventos da janela e do teclado, tratar o encerramento da aplicação e converter inputs relevantes em comandos para a lógica local.
2. `update()`: processar comandos, validar movimento e colisão e atualizar o estado do mundo por meio do backend.
3. `render()`: calcular coordenadas de tela, aplicar a câmera, desenhar o estado atual e apresentar o frame por meio do cliente e da SDL3.

Essa separação deverá impedir que regras do mundo sejam incorporadas à etapa de renderização e permitir que backend e shared sejam usados sem inicializar SDL3 ou uma janela.

## Estado atual

Esta arquitetura é exclusivamente documental e planejada. Nenhum game loop, sistema de coordenadas, movimento, janela, câmera, renderização ou integração com o Canary é implementado por este documento.
