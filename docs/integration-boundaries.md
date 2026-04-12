# Integration Boundaries

## Objetivo
Este documento registra os limites iniciais de integração entre servidor, cliente, mapas, assets e tools no projeto RestPK.

## Limite entre servidor e cliente
- o servidor deve concentrar a lógica principal do jogo
- o cliente deve concentrar apresentação, interface e interação do jogador
- o cliente não deve assumir a lógica central que pertence ao servidor
- o servidor não deve assumir responsabilidades de apresentação visual

## Limite entre servidor e mapas
- o servidor deve interpretar e utilizar a estrutura dos mapas
- os mapas devem servir como base espacial do jogo
- a lógica do jogo não deve ficar espalhada de forma desorganizada dentro da área de mapas

## Limite entre cliente e assets
- o cliente deve consumir recursos visuais e auxiliares
- os assets devem servir de apoio visual ao projeto
- os assets não devem definir a lógica principal do jogo

## Limite entre projeto principal e tools
- tools devem atuar como apoio técnico
- tools não devem se tornar o núcleo do projeto
- scripts auxiliares devem existir para suporte, não para substituir a organização principal do repositório

## Observação
Este documento existe para reduzir ambiguidade de responsabilidades antes da integração técnica real da stack.