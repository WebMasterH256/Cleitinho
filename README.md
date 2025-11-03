# Projeto cleitinho
Participantes : *Mateus* e *Raíssa*.

Olá, nosso projeto cleitinho foi planejado inicialmente para caber em um arquivo só. Mas percebemos que acabaria sendo grande demais para caber em um único arquivo **main**.
Então separamos cada parte importante do código em uma pasta contendo os **headers** e o código pronto. Também criamos um arquivo **util** contendo versões aturalizadas do _scanf_ (lerInteiro, lerString, etc),
para impedir o usuário de cometer um erro digitando um tipo de dado errado quebrando a execução do código de forma antecipada.

## Sobre as pastas

### Clientes

Abriga o struct cliente as funcões necessárias para criar, salvar e remover os clientes.

### Ordens

Inclui funções nescessárias para registrar, consultar e alterar ordens, conectando clientes e peças.

### Peças

Contém as funções nescessárias para o armazenamento/controle de estoque.

### Util

Contém as funções que substituem o scanf, uma função para limpar a tela independente do sistema operacional e uma para pausar a tela.


