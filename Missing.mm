
1. (GRAVE) Do ponto de vista de estruturação, a lista de peças deveria ser atributo do Jogo, e criada de forma
independente da TAD Peca. Não estou entendendo, pois parece que temos 2 listas em Jogo e uma em Tabuleiro. Além
disso, Peca não deveria ser uma estrutura "encadeável". Não consegui entender o uso da lista de peças em
tabuleiro....

2. (GRAVÍSSIMO) O tabuleiro deveria ser uma matriz [8][8] de PONTEIROS para Peca, e não uma matriz de Peca. Isto
afeta praticamente todas as funções do programa e deve ser refeita.
	
Done	-	3. (SUGESTÃO) Evitar fazer entrada de dados de usuário dentro de funções das TADs. O correto é fazer a leitura das
informações "fora" da função, e passá-las como parâmetros (estou olhando, neste caso, para criaJogo).

4. (GRAVÍSSIMO) Notem que, devido ao problema indicado no item 2, o programa está DUPLICANDO todas as peças na
memória. Vocês criam um conjunto de peças na lista de Jogo e, depois repetem a criação de outro conjunto de peças
para ser passado para o Tabuleiro. Isto precisa ser corrigido.

5. (IMPORTANTE) Mais problemas estruturais no projeto: 
	a. A responsabilidade na tarefa de realizar uma jogada
poderia ter sido melhor dividida. Algumas coisas que deveriam ser pertinentes ao Tabuleiro estão sendo realizadas
por Jogo (isto não é necessariamente um erro, mas a forma como está implementado poderia ser melhorada). De
qualquer maneira, a tarefa está dividida entre Jogo-Tabuleiro-Peca.

6. (IMPORTANTE) Código com alguns vícios ruins. 
	a. Comparações duplicadas do símbolo da peça (para maiúscula e
minúscula). Isso pode ser resolvido convertendo sempre o símbolo para maiúscula (ou minúscula), antes de realizar a
verificação do tipo da peça (caso em que o lado não importa). 
	b. Uso de uma peça "Nula". Desperdício de memória e
tratamento. Esse problema também decorre de 2 (se o tabuleiro fosse uma matriz de ponteiros, bastaria fazê-los
nulos.

7. (MENOR) Problemas de interface: 
Done	-	a. As peças brancas devem ser posicionadas na parte de baixo do tabuleiro, e as
linhas ordenadas de baixo para cima. 
Done	-	b. Seria bom, além dos nomes dos jogadores, indicar a cor da peça da vez. 
	c. Algumas mensagens erradas. Ex. Quando tentei jogar com as pretas, na vez das brancas, a mensagem que recebi foi:
Coordenada de origem inválida. Isso me fez perder algum tempo, achando que estava digitando errado, ou que o
programa não reconhecia minúsculas, etc.

8. (IMPORTANTE) uma entrada incorreta na interface faz o programa capotar.

IMPORTANTE: não se impressionem com a quantidade de comentários. O projeto está bom e o funcionamento do programa
atende aos requisitos. Entretanto, sugiro fortemente que o grupo aplique as alterações sugeridas.
	
