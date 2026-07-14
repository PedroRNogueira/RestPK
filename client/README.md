# Client Directory

## Objetivo

Este diretório será responsável pela camada visual e de interação do RestPK. Uma primeira versão do cliente deverá ser desenvolvida para o protótipo jogável local antes da integração completa do OTClient mehah / OpenTibiaBR e do Canary.

Essa descrição registra apenas a direção planejada. As funcionalidades do protótipo ainda não estão implementadas.

## Primeiro papel planejado

No primeiro marco jogável, o cliente deverá:

- abrir a janela do jogo;
- executar a renderização;
- capturar entradas de teclado, incluindo WASD e setas direcionais;
- desenhar um mapa pequeno e seus tiles de chão;
- desenhar o personagem;
- controlar uma câmera que acompanhe o jogador;
- apresentar o estado recebido da lógica local.

Animações e uma interface visual mais completa poderão ser incorporadas em etapas futuras.

## Separação de responsabilidades

O cliente deverá cuidar da apresentação e da entrada, sem concentrar a validação das regras do mundo. Estado do mundo, posição válida do jogador, movimento, colisões, limites do mapa e estado das entidades deverão permanecer na lógica local de `backend/`.

Os contratos necessários à comunicação entre apresentação e lógica deverão permanecer independentes de bibliotecas gráficas e de detalhes específicos do Canary, conforme a direção de `shared/`. Assim, a futura integração do Canary poderá substituir ou adaptar a lógica local sem exigir uma reestruturação completa do cliente.

## Stack futura

O OTClient mehah / OpenTibiaBR continua sendo a base planejada para o cliente final no ecossistema OpenTibia. Sua importação completa ocorrerá em uma etapa posterior e não faz parte da fase documental atual.

## Estado atual

O diretório ainda está em preparação. Nesta etapa, não há implementação de gameplay, código C++, build, biblioteca gráfica, importação do OTClient ou integração com o Canary.

Também permanecem fora deste primeiro marco a interface final, os assets finais e os sistemas avançados de gameplay.
