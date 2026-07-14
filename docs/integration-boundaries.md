# Limites de integração

## Objetivo

Este documento define as fronteiras planejadas entre cliente, lógica local, contratos compartilhados, mapas, assets, ferramentas e a futura integração do Canary no RestPK.

## Cliente: apresentação e entrada

O `client/` deverá ser responsável por:

- abrir e manter a janela da aplicação;
- capturar a entrada do jogador;
- renderizar mapa, personagem e interface;
- controlar a câmera;
- apresentar o estado fornecido pela lógica local.

O cliente poderá transformar entradas em solicitações de ação, mas não deverá concentrar a validação central de movimento, colisão ou demais regras do mundo.

## Backend local: regras e estado

Na fase do protótipo, o `backend/` deverá ser uma camada de lógica executada localmente e independente da renderização. Ele deverá manter o estado do mundo e das entidades, validar movimento, colisões e limites do mapa e produzir o estado que será apresentado pelo cliente.

Esse backend local não deverá ser tratado como servidor multiplayer. Neste recorte não estão previstos servidor HTTP, API REST, login, banco de dados, comunicação de rede ou sincronização entre jogadores.

## Shared: contratos independentes

O `shared/` deverá reunir estruturas e contratos usados na comunicação entre apresentação e lógica. Posição, direção, tile, criatura, solicitação de movimento, resultado de movimento e estado básico de entidade são exemplos conceituais futuros.

Esses contratos deverão evitar dependências gráficas, detalhes internos do cliente e dependências específicas do Canary. Assim, a origem do estado poderá mudar no futuro sem obrigar o cliente a conhecer a implementação responsável por produzi-lo.

## Mapas: espaço jogável

O `map/` deverá representar o espaço jogável, incluindo a disposição dos tiles e os dados espaciais necessários ao protótipo. O backend local deverá interpretar esses dados ao validar o estado do mundo e o deslocamento das entidades.

Os mapas não deverão concentrar regras gerais de gameplay nem assumir responsabilidades de renderização.

## Assets: recursos de apresentação

O `assets/` deverá armazenar recursos visuais e outros materiais de apresentação consumidos pelo cliente. Assets não deverão definir regras, validar movimentos ou controlar o estado do jogo.

## Server e futura integração do Canary

O `server/` permanecerá reservado para a futura integração do Canary. O Canary será integrado somente depois que o protótipo local validar os fundamentos de mapa, chão, personagem, movimento, colisão e câmera.

Nessa etapa futura, o Canary deverá substituir ou adaptar parte ou toda a lógica atualmente planejada para execução local. A separação por contratos deverá permitir essa troca sem exigir uma reestruturação completa da camada de apresentação.

## Tools: apoio técnico

O `tools/` deverá conter apenas ferramentas auxiliares. Scripts e editores poderão apoiar o fluxo de desenvolvimento, mas não deverão se tornar o núcleo da aplicação nem substituir as responsabilidades do cliente, do backend ou dos contratos compartilhados.

## Fluxo planejado

O fluxo básico do protótipo deverá seguir esta direção:

1. o cliente captura a entrada;
2. um contrato compartilhado representa a solicitação;
3. o backend local valida a ação e atualiza o estado;
4. um contrato compartilhado expõe o resultado ou o novo estado;
5. o cliente apresenta esse estado.

Esse fluxo deverá manter a lógica central desacoplada do sistema gráfico. A renderização não deverá ser necessária para testar regras de movimento, colisão ou estado.

## Estado atual

As fronteiras descritas aqui são uma direção arquitetural planejada. Elas não indicam que o protótipo local, seus contratos ou a integração com o Canary já tenham sido implementados.
