# RestPK

## Visão geral

RestPK é um projeto de jogo inspirado em Tibia com temática Pokémon. O foco técnico atual é um protótipo jogável local, anterior à futura integração com Canary e OTClient.

## Estado atual do protótipo

O primeiro marco jogável local está implementado em C++20 com CMake, vcpkg e SDL3. A aplicação abre uma janela de `1280x720`, desenha um mapa lógico de `50x35` tiles, mostra o jogador e permite movimentação com colisão e câmera.

O mapa é criado em código e contém chão, obstáculos e bordas bloqueadas. Cada comando tenta mover o jogador exatamente um tile de `32x32` pixels; o backend rejeita destinos fora dos limites ou não caminháveis sem alterar a posição atual.

A arquitetura mantém as responsabilidades separadas:

- `client/`: janela, eventos, controles, câmera, coordenadas de tela e renderização SDL3;
- `backend/`: mapa lógico, jogador, regras de movimento, limites e colisão;
- `shared/`: posições, direções, tiles e resultado de movimento, sem dependência gráfica;
- `server/`: espaço reservado para a futura integração do Canary.

`backend/` e `shared/` não incluem nem vinculam SDL3. Coordenadas em pixels existem somente no cliente.

## Controles

| Ação | Teclas |
| --- | --- |
| Mover para cima | `W` ou seta para cima |
| Mover para a direita | `D` ou seta para a direita |
| Mover para baixo | `S` ou seta para baixo |
| Mover para a esquerda | `A` ou seta para a esquerda |
| Fechar | botão `X` da janela |

O movimento ocorre uma vez por pressionamento. Repetições automáticas do teclado são ignoradas; não há movimento diagonal, contínuo, animação, autowalk ou pathfinding.

## Configurar, compilar e executar no Windows

Use o **Developer PowerShell for VS 2022** com arquitetura x64, a partir da raiz do repositório. São necessários Visual Studio 2022 com suporte a C++, CMake e uma instalação inicializada do vcpkg.

Defina `VCPKG_ROOT` e execute:

```powershell
$env:VCPKG_ROOT = "C:\src\vcpkg"
cmake --preset windows-msvc-x64
cmake --build --preset windows-msvc-x64-debug
.\build\windows-msvc-x64\client\Debug\restpk_client.exe
```

O manifesto instala somente SDL3. O executável esperado é `build/windows-msvc-x64/client/Debug/restpk_client.exe`.

Este fluxo foi validado em Debug com MSVC 2022 x64. A validação local cobriu abertura da janela, mapa e jogador visíveis, WASD, quatro setas, movimento de um tile, colisão com obstáculos e bordas, acompanhamento e limites da câmera, fechamento normal e código de saída `0`.

## Estrutura implementada

```text
shared/include/restpk/
  Position.hpp
  Direction.hpp
  Tile.hpp
  MovementResult.hpp

backend/include/restpk/
  Player.hpp
  World.hpp
backend/src/
  Player.cpp
  World.cpp

client/include/restpk/
  Camera.hpp
  Game.hpp
client/src/
  Camera.cpp
  Game.cpp
  main.cpp
```

## Limitações atuais

- o mapa é fixo, criado em memória e não possui carregamento externo;
- chão, obstáculos e jogador usam apenas retângulos coloridos da SDL3;
- há somente um jogador local, sem NPCs, Pokémon, inventário ou combate;
- não existem sprites, fontes, áudio, animações ou múltiplos andares funcionais;
- não há persistência, multiplayer, rede, Canary ou OTClient;
- a câmera acompanha apenas o mundo local atual, sem efeitos ou transições.

Esses sistemas permanecem fora deste primeiro recorte jogável e devem ser adicionados em tarefas futuras e isoladas.
