# Contratos compartilhados

O diretório `shared/` está planejado para reunir contratos e estruturas independentes que possam ser usados tanto pelo cliente quanto pela lógica local. Ele deverá definir a forma dos dados trocados entre essas camadas sem assumir como eles serão renderizados ou validados.

Exemplos conceituais de estruturas futuras incluem:

- `Position`;
- `Direction`;
- `Tile`;
- `Creature`;
- `MovementRequest`;
- `MovementResult`.

Esses nomes servem apenas para orientar a arquitetura inicial. Nenhuma dessas estruturas está implementada e nenhum arquivo de código correspondente deve ser considerado existente nesta etapa.

O conteúdo futuro de `shared/` deverá evitar dependências gráficas e dependências específicas do Canary. Assim, os mesmos contratos poderão apoiar o protótipo local e, posteriormente, a integração com o servidor sem prender a lógica central à apresentação ou a uma implementação específica.
