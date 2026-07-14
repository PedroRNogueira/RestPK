# Backend local

O diretório `backend/` está planejado como a camada de lógica local do primeiro protótipo jogável do RestPK. Seu conteúdo deverá permanecer independente da renderização e da interface visual, permitindo que o cliente apenas apresente o estado do jogo e encaminhe as entradas do jogador.

## Responsabilidades planejadas

Esta camada deverá concentrar:

- o estado do mundo e seus limites;
- a posição e o estado do jogador;
- as regras de movimento;
- a detecção e validação de colisões;
- a validação das regras básicas do jogo;
- o estado das demais entidades, quando elas forem introduzidas.

Essas responsabilidades ainda não estão implementadas. Elas deverão ser desenvolvidas em etapas pequenas durante a construção do protótipo local.

## Limite desta fase

O `backend/` não representa um servidor multiplayer. Nesta fase, não estão previstos servidor HTTP, API REST, comunicação de rede, login, contas ou banco de dados. Também não se pretende aplicar uma arquitetura web genérica à lógica do jogo.

## Integração futura com o Canary

O Canary permanece reservado para uma etapa posterior. A separação entre apresentação, contratos e regras deverá permitir que a lógica local seja substituída ou adaptada para o Canary sem exigir uma reestruturação completa do cliente.

Até essa integração, o estado do mundo, o movimento e as colisões poderão ser validados inteiramente em execução local.
