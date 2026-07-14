# Client Next Steps

## Objetivo

Este documento registra a ordem planejada para construir a camada visual do protótipo jogável local antes da integração completa do OTClient e do Canary. Cada item deverá ser executado e validado em uma task pequena.

## Ordem aproximada de implementação

1. Escolher a base gráfica inicial.
2. Preparar projeto C++ mínimo.
3. Configurar build.
4. Abrir janela.
5. Criar game loop.
6. Renderizar tile de chão.
7. Renderizar personagem.
8. Implementar entrada.
9. Integrar posição com a lógica local.
10. Implementar câmera.

## Escolha da base gráfica

A biblioteca gráfica inicial ainda não está definida. A avaliação e a escolha entre SDL2, SFML ou outra alternativa deverão ocorrer em uma task específica, sem adicionar dependências nesta etapa documental.

## Separação da lógica

Os passos do cliente deverão permanecer limitados à janela, ao game loop, à renderização, à entrada por WASD e setas direcionais e à câmera que acompanha o jogador. O cliente poderá enviar solicitações de movimento e apresentar o estado resultante, mas a lógica local deverá ser responsável pela posição válida, pelas regras de movimento, pelas colisões e pelos limites do mapa.

Os contratos entre essas camadas deverão evitar dependências gráficas e detalhes específicos do Canary. Essa separação deverá permitir que a lógica local seja substituída ou adaptada durante a futura integração com o Canary sem reestruturar completamente a apresentação.

## Limites desta sequência

Esta sequência ainda não inclui a importação completa do OTClient, a integração do Canary, multiplayer, comunicação de rede, interface final, assets finais ou sistemas avançados de gameplay. Nenhum dos passos listados está sendo declarado como implementado por este documento.
