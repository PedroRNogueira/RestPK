# Agent Rules

## 1. Contexto do projeto
- RestPK é um jogo inspirado em Tibia com temática Pokémon.
- Stack planejada:
  - Canary
  - OTClient mehah / OpenTibiaBR
  - Remere's Map Editor
  - C++ e Lua
- Foco atual:
  - documentação
  - alinhamento técnico
  - fundação do projeto

## 2. Regras permanentes
- trabalhar em tarefas pequenas
- não sair do escopo solicitado
- alterar somente os arquivos pedidos
- não inventar stack web genérica quando isso não fizer sentido para o ecossistema OT
- documentar tudo que mudar
- não refatorar sem necessidade
- evitar mudanças grandes em uma única task
- manter consistência com o ecossistema OT

## 3. Regra obrigatória de conclusão e publicação
- a tarefa só é considerada concluída se a alteração estiver no GitHub remoto
- não basta editar localmente, mostrar diff, ou dizer que fez push
- no final de cada task, obrigatoriamente executar:
  - git add <arquivos alterados>
  - git commit -m "<mensagem de commit>"
  - git push origin main
  - git rev-parse HEAD
  - git ls-remote origin refs/heads/main
- comparar o hash local com o hash remoto da main
- só declarar sucesso se os dois hashes forem iguais
- se o push falhar, se o hash remoto não mudar, ou se não conseguir verificar, declarar explicitamente que a tarefa NÃO foi concluída
- se aparecer "accept edits", a tarefa ainda não terminou

## 4. Formato de resposta final obrigatório
- hash local do commit
- hash remoto da main
- arquivos alterados
- confirmação explícita se o remoto foi atualizado ou não
- resumo curto do que foi feito