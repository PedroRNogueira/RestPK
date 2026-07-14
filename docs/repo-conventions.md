# Repo Conventions

## Objetivo
Este documento registra as convenções oficiais do repositório RestPK para reduzir ambiguidade durante a evolução do projeto.

## Stack técnica oficial

- a linguagem do protótipo é C++20
- o compilador principal é MSVC 2022 x64
- a base gráfica do cliente é SDL3
- o sistema de build é CMake
- as configurações reproduzíveis de build são registradas em `CMakePresets.json`
- as dependências são gerenciadas pelo vcpkg em Manifest Mode e declaradas em `vcpkg.json`

Essas escolhas são oficiais. A existência desta convenção não significa que o projeto CMake, os manifests, as dependências ou o código já tenham sido criados.

## Convenções gerais
- cada área principal do projeto deve manter documentação mínima coerente com sua função
- mudanças devem respeitar a separação entre cliente, backend local, contratos compartilhados, servidor futuro, mapas, assets e tools
- a organização do repositório deve priorizar clareza antes de volume de conteúdo
- tarefas devem avançar em pequenos passos verificáveis
- o protótipo jogável local deve ser validado antes da integração com o Canary

## Convenções arquiteturais

- `client/` concentra renderização, janela, câmera e input
- `backend/` concentra regras, mundo, colisão e movimento
- `shared/` concentra `Position`, `Direction`, `Tile` e demais contratos compartilhados
- `server/` fica reservado para a futura integração do Canary
- `backend/` e `shared/` não dependem da SDL3
- dependências de apresentação e plataforma não devem vazar do `client/` para a lógica ou para os contratos compartilhados

## Convenções de coordenadas e movimento

- coordenadas de mundo usam `x`, `y` e `z`
- coordenadas de tela são calculadas apenas pelo `client/`
- o tile visual inicial mede `32x32` pixels
- o movimento inicial usa quatro direções e avança um tile por comando
- diagonal, animação, autowalk e pathfinding ficam fora do movimento inicial

## Convenção do game loop

O loop planejado segue `processEvents()`, `update()` e `render()`, nessa ordem:

- `processEvents()` coleta eventos e input
- `update()` aplica as regras e atualiza o estado
- `render()` apresenta o estado pelo cliente

## Convenções de documentação
- documentos devem ser curtos, objetivos e coerentes com o estado atual do projeto
- documentos não devem prometer implementação já concluída quando ela ainda não existe
- documentos devem evitar linguagem genérica de stack que não combine com o ecossistema OT
- mudanças de decisão técnica devem atualizar os documentos técnicos autoritativos antes de serem tratadas como convenção do projeto

## Fontes de verdade técnicas

- `docs/technical-stack.md` define a stack oficial e substitui registros anteriores que tratem SDL2, SFML, a base gráfica, o build ou o gerenciamento de dependências como escolhas pendentes.
- `docs/rendering-architecture.md` define as responsabilidades de renderização, os sistemas de coordenadas, o movimento inicial e o game loop.
- `docs/first-technical-scope.md` define a ordem técnica atual e substitui planos anteriores que coloquem o bootstrap do servidor antes do protótipo jogável local.

Quando um documento legado divergir dessas fontes dentro dos temas acima, prevalece o documento técnico correspondente.

## Convenções de execução
- cada task deve alterar somente o necessário
- o remoto deve ser tratado como fonte de verdade
- uma task não deve ser considerada concluída sem commit, push e verificação remota
- a evolução do projeto deve seguir a ordem vigente em `docs/first-technical-scope.md` e as decisões oficiais de `docs/technical-stack.md` e `docs/rendering-architecture.md`

## Observação
Este documento existe para manter consistência no repositório antes da implementação real da stack. Nesta etapa, ele não autoriza a criação de código, arquivos de build, dependências, janelas ou gameplay.
