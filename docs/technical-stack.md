# Stack técnica oficial

## Objetivo

Este documento registra a stack técnica oficial do protótipo jogável local do RestPK. As escolhas abaixo orientam as próximas tasks de implementação, sem antecipar a importação do OTClient ou a integração com o servidor Canary.

O protótipo local servirá para validar janela, renderização, câmera, entrada, mundo, colisão e movimento. A separação entre apresentação, lógica e contratos deverá preservar a direção futura do projeto no ecossistema OpenTibia, permitindo que o Canary seja integrado posteriormente sem concentrar suas responsabilidades no cliente.

## Decisões oficiais

- **Linguagem — C++20:** oferece recursos modernos da linguagem, tipagem forte e desempenho adequado à base do jogo, mantendo coerência com o ecossistema C++ planejado para o RestPK.
- **Compilador principal — MSVC 2022 x64:** estabelece uma ferramenta principal e uma arquitetura de 64 bits para o ambiente Windows, com suporte ao padrão C++20 e integração com o fluxo de desenvolvimento previsto.
- **Base gráfica — SDL3:** será a biblioteca oficial do protótipo para abstrair janela, eventos e entrada e apoiar a renderização sem acoplar essas responsabilidades às regras do mundo.
- **Sistema de build — CMake:** centralizará a descrição do build e permitirá gerar o projeto para a ferramenta principal sem vincular sua estrutura aos arquivos de uma IDE.
- **Configuração de build — `CMakePresets.json`:** registrará configurações reproduzíveis de configuração e build, reduzindo diferenças entre comandos e ambientes de desenvolvimento.
- **Gerenciador de dependências — vcpkg em Manifest Mode:** declarará as dependências do projeto por meio de manifesto versionado no repositório e oferecerá integração consistente com CMake e MSVC.

Essas decisões são oficiais para o protótipo jogável local. Elas não significam que as ferramentas, bibliotecas ou configurações já estejam instaladas ou adicionadas ao repositório.

Este documento é a fonte de verdade para a stack do protótipo. Registros anteriores que tratem a base gráfica, o sistema de build ou o gerenciamento de dependências como escolhas ainda pendentes ficam substituídos por estas decisões.

## Arquitetura planejada

O projeto seguirá esta divisão de responsabilidades:

- `client/`: janela, renderização, câmera e entrada do jogador;
- `backend/`: regras, estado do mundo, colisão e movimento executados localmente no protótipo;
- `shared/`: contratos compartilhados, incluindo futuramente `Position`, `Direction` e `Tile`;
- `server/`: espaço reservado para a futura integração do Canary.

A SDL3 pertencerá à camada de apresentação em `client/`. `backend/` e `shared/` não dependerão da SDL3 nem de outros detalhes de renderização. Essa fronteira permitirá testar regras e contratos sem abrir uma janela e facilitará a futura substituição ou adaptação da lógica local durante a integração com o Canary.

## Coordenadas e tiles

As coordenadas de mundo serão representadas por:

- `x`: posição horizontal no mundo;
- `y`: posição vertical no mundo;
- `z`: nível ou andar no mundo.

As coordenadas de tela serão calculadas exclusivamente pelo `client/`, a partir da posição no mundo e do estado da câmera. Regras do `backend/` e contratos de `shared/` não deverão depender de posições em pixels.

O tamanho inicial de cada tile será de **32 x 32 pixels** na apresentação do protótipo.

## Primeiro movimento

O primeiro recorte de movimento terá:

- quatro direções;
- deslocamento de um tile por comando;
- nenhuma diagonal;
- nenhuma animação;
- nenhum autowalk;
- nenhum pathfinding.

O `client/` capturará o comando, enquanto o `backend/` validará e aplicará o deslocamento no mundo por meio dos contratos definidos em `shared/`.

## Game loop

O loop principal planejado seguirá esta ordem:

```text
processEvents()
update()
render()
```

- `processEvents()` receberá os eventos da janela e a entrada do jogador, incluindo a solicitação de encerramento e os comandos de movimento.
- `update()` encaminhará ações para a lógica local, validará as regras necessárias e atualizará o estado do mundo.
- `render()` converterá o estado do mundo em coordenadas de tela e desenhará a cena pelo `client/`.

A renderização apenas apresentará o estado resultante; ela não será responsável por validar movimento, colisão ou outras regras do mundo.

## Estrutura alvo

A estrutura alvo do projeto é:

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

Essa árvore documenta o destino planejado. Este documento não cria os arquivos de build, manifestos, diretórios ou conteúdos nela representados.

## Estado atual

Esta etapa é exclusivamente documental. Não há implementação de código C++, projeto CMake, presets de build, manifesto vcpkg, dependência SDL3, janela, game loop, mapa, renderização, movimento, assets ou gameplay resultante destas definições.

A integração do Canary e a importação completa do cliente OpenTibia continuam reservadas para fases futuras, depois que os fundamentos do protótipo jogável local forem implementados e validados em tasks próprias.
