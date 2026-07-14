# RestPK

## Visão geral

RestPK é um projeto de jogo inspirado em Tibia com temática Pokémon. O foco técnico atual é preparar um protótipo jogável local antes da futura integração com o Canary.

## Estado atual do projeto

O projeto possui o bootstrap técnico mínimo do cliente local com C++20, CMake, vcpkg e SDL3. A aplicação já abre uma janela, cria um renderer, executa o game loop e encerra corretamente; o protótipo jogável, o Canary e o OTClient ainda não foram implementados ou importados.

A arquitetura oficial separa as seguintes responsabilidades:

- `client/`: renderização, janela, câmera e input;
- `backend/`: regras, mundo, colisão e movimento;
- `shared/`: tipos como `Position`, `Direction` e `Tile`, além dos contratos compartilhados;
- `server/`: espaço reservado para a futura integração do Canary.

`backend/` e `shared/` não dependem da SDL3. Essa separação deve permitir que a lógica inicial seja executada localmente e que, em uma etapa posterior, o Canary substitua ou adapte essa camada sem exigir uma reestruturação completa do cliente e dos contratos compartilhados.

## Primeiro objetivo jogável

O primeiro marco técnico será uma aplicação local capaz de abrir uma janela e executar um game loop, apresentar um mapa pequeno com tiles de chão e um personagem, permitir movimento por tiles com WASD e setas direcionais, bloquear tiles não caminháveis, acompanhar o jogador com uma câmera e exibir temporariamente sua posição para depuração.

Esse marco será construído em tasks pequenas. Sistemas de gameplay avançado, conteúdo definitivo, multiplayer e comunicação de rede permanecem fora desse primeiro recorte.

## Stack técnica oficial

- **Linguagem — C++20:** oferece recursos modernos da linguagem com um padrão estável e amplamente suportado pelas ferramentas escolhidas.
- **Compilador principal — MSVC 2022 x64:** define um ambiente principal consistente para desenvolvimento e validação no Windows em 64 bits.
- **Base gráfica — SDL3:** fornece a camada oficial de janela, eventos, input e renderização do cliente sem acoplar a lógica do jogo à plataforma.
- **Sistema de build — CMake:** descreve o build de forma declarativa e mantém aberta a evolução multiplataforma do projeto.
- **Configuração de build — `CMakePresets.json`:** padroniza configurações e comandos de build reproduzíveis entre os colaboradores.
- **Gerenciador de dependências — vcpkg em Manifest Mode:** declara as dependências do projeto de forma versionável por meio de `vcpkg.json`.

A integração do Canary fica adiada até que os fundamentos do protótipo jogável local tenham sido validados. O bootstrap atual começa a materializar essa stack sem antecipar sistemas de jogo.

## Escopo do bootstrap SDL3

A aplicação mínima desta etapa deverá:

- abrir uma janela com SDL3;
- criar e manter um renderer;
- executar o loop `processEvents()`, `update()` e `render()`;
- limpar a tela e apresentar cada frame;
- tratar o fechamento pelo botão X e liberar os recursos da SDL3 corretamente.

`update()` poderá permanecer vazio enquanto não houver estado de jogo. O `client/` continuará responsável por janela, eventos e renderização, sem mover dependências da SDL3 para `backend/` ou `shared/`.

## Configurar, compilar e executar no Windows

Use o **Developer PowerShell for VS 2022** com a arquitetura x64, a partir da raiz do repositório. O Visual Studio 2022 com suporte a desenvolvimento C++, o CMake e uma instalação inicializada do vcpkg devem estar disponíveis.

Defina `VCPKG_ROOT` com o caminho da instalação do vcpkg e execute:

```powershell
$env:VCPKG_ROOT = "C:\src\vcpkg"
cmake --preset windows-msvc-x64
cmake --build --preset windows-msvc-x64-debug
.\build\windows-msvc-x64\client\Debug\restpk_client.exe
```

O executável esperado é `build/windows-msvc-x64/client/Debug/restpk_client.exe`.

Esse fluxo foi validado com MSVC 2022 x64 em build Debug, incluindo a instalação da SDL3 pelo vcpkg, a geração do executável e a abertura e o fechamento normal da janela.

## Fora do escopo deste bootstrap

Esta etapa não implementa mapa, tiles, jogador, câmera, sprites, colisão, movimento, assets, OTClient, Canary ou networking. Também não adiciona SDL3_image, SDL3_ttf ou SDL3_mixer.

## Convenções iniciais do protótipo

- Posições no mundo usam as coordenadas `x`, `y` e `z` (`World`).
- Coordenadas de tela (`Screen`) são calculadas exclusivamente pelo `client/`.
- O tile visual inicial tem `32x32` pixels.
- O primeiro movimento aceita quatro direções e desloca um tile por comando, sem diagonal, animação, autowalk ou pathfinding.
- O game loop planejado segue `processEvents()`, `update()` e `render()`: respectivamente coleta eventos e input, atualiza regras e estado, e desenha o estado atual.

## Estrutura alvo

```text
RestPK
├── CMakeLists.txt
├── CMakePresets.json
├── vcpkg.json
├── client/
├── backend/
├── shared/
├── server/
├── map/
├── assets/
└── tools/
```

Essa árvore representa o alvo técnico geral. O bootstrap atual cobre a base de build e a aplicação SDL3 mínima descrita acima; os sistemas do protótipo jogável permanecem para as próximas tasks.
