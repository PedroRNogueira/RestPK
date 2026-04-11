# OT Stack

## Objetivo
Este documento registra a função de cada componente principal da stack planejada do RestPK.

## Servidor
O servidor planejado do projeto é o **Canary**.

Função no projeto:
- controlar a lógica principal do jogo
- processar entidades, regras e estados do mundo
- servir como base da lógica de gameplay
- centralizar scripts e comportamento do jogo

## Cliente
O cliente planejado do projeto é o **OTClient mehah / OpenTibiaBR**.

Função no projeto:
- apresentar a interface visual do jogo
- exibir mapa, entidades e interações
- permitir movimentação e ações do jogador
- servir como base para futuras customizações visuais e funcionais

## Editor de mapa
O editor de mapa planejado do projeto é o **Remere's Map Editor**.

Função no projeto:
- criar e editar mapas
- organizar áreas jogáveis
- estruturar cidade inicial, rotas e mapas secundários
- preparar o conteúdo espacial do jogo

## Linguagens principais
- **C++** para a base principal do ecossistema OT
- **Lua** para scripts, eventos e comportamento de jogo

## Relação entre os componentes
- o servidor define a lógica e o estado do mundo
- o cliente apresenta esse mundo ao jogador
- o editor de mapa prepara os ambientes que serão usados pelo projeto

## Observação
Nesta etapa, este documento serve apenas para alinhar tecnicamente a stack do projeto.
Ainda não é a etapa de instalar, integrar ou customizar profundamente esses componentes.