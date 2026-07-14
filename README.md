# RestPK

## Visão geral

RestPK é um projeto de jogo inspirado em Tibia com temática Pokémon. O foco técnico atual é preparar um protótipo jogável local antes da futura integração com o Canary.

## Estado atual do projeto

O projeto está em uma etapa documental e estrutural. O protótipo local e o gameplay ainda não foram implementados, e o Canary e o OTClient ainda não foram importados.

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

A integração do Canary fica adiada até que os fundamentos do protótipo jogável local tenham sido validados. A stack acima é oficial, mas ainda não foi implementada ou adicionada ao repositório nesta etapa documental.

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

Essa árvore representa o alvo técnico. Esta atualização não cria os arquivos de build, instala dependências nem implementa código, janela ou gameplay.
