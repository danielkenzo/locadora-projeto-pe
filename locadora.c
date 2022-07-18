//Projeto Locadora

#include <stdio.h>
#include <string.h>

void listarFilmes(int opcao);
void detalhesDoFilme(int opcao);
void adicionarCarrinho(int codigoFilme);
void removerCarrinho(int codigoFilme);
void precoCarrinho(int genero);
void subtotalCompra();
void limparCarrinho();


struct listaFilmes{
	char nome [30], sinopse[400];
	double nota;
	int ano;
};


int contador = 0, opcao, valor[48];
//char* matriz_itens [10][10];

int main() {
	int menu, opcaoDois, opcaoFinal, entrada, codigo;
	
	do{
		printf("\nDigite 1 para entrar no menu ou 0 para encerrar:\n");
	    scanf("%d", &menu);
	  
		if(menu==1){
			do{
				printf("\nEscolha o tipo do filme:\n[1] Ação    |  [2] Aventura  |  [3] Comédia   |  [4] Suspense "
              "\n[5] Drama   |    [6] Terror  |  [7] Subtotal  |  [0] Voltar \n");
				scanf("%d", &entrada);
				
				if(entrada!=0){
					if(entrada>0 && entrada<=6){
						do{
							listarFilmes(entrada);
							printf("\nDigite o código do filme para exibir mais detalhes ou 0 para voltar:\n");
							scanf("%i", &opcao);
							
							if (opcao<0||opcao>8) {
								do {
									printf("\nCódigo incorreto. Digite novamente o código do filme desejado ou 0 para voltar:\n ");
									scanf("%i", &opcao);
								}while(opcao<0||opcao>8);
							}
							
							if(opcao!=0){
								detalhesDoFilme(opcao);
								printf("\n[1] Adicionar ao carrinho  |  [0] Voltar\n");
								scanf("%i", &opcaoDois);
								
								if(opcaoDois==1){
									adicionarCarrinho(opcao);
									precoCarrinho(entrada);
									contador++;
								}
							}
						}while(opcao!=0);
					}
					
					else if(entrada==7){
						do{
							subtotalCompra(entrada);
							printf("\n[1] Remover do carrinho  |  [2] Encerrar compra  |  [0] Voltar\n");
							scanf("%i", &opcaoFinal);
              
							if(opcaoFinal==1){
								printf("\nDigite o código do título que deseja remover:\n");
								scanf("%i", &codigo);
								removerCarrinho(codigo);
							}
							
							else if(opcaoFinal==2){
								subtotalCompra(opcaoFinal);
								entrada=0;
							}
						}while(opcao!=0);
					}
					
					else{
						printf("Opção não disponível.\n");
					}
				}
			}while(entrada!=0);
		}	
    
		if(opcaoFinal==2){
			limparCarrinho();
		}
	}while(menu!=0);
    
	printf("Programa finalizado!");
}

void listarFilmes(int opcao){
	struct listaFilmes filmes[100];
	    if(opcao==1){
      printf("\nCada filme dessa categoria custa R$: 1.00");
			strcpy(filmes[0].nome, "Duro de Matar");
			filmes[0].nota = 8.2;
			filmes[0].ano = 1988;
			strcpy(filmes[0].sinopse, "Duro de Matar é uma série cinematográfica estadunidense de filmes de ação que teve início em 1988 com o filme-título, baseado no romance Nothing Lasts Forever de Roderick Thorp.");
			strcpy(filmes[1].nome, "Velozes e Furiosos");
			filmes[1].nota = 6.8;
			filmes[1].ano = 2001;
			strcpy(filmes[1].sinopse, "The Fast and the Furious é uma saga americana, criada em 2001, que se integra na categoria de filmes de ação. Esta saga concentra-se em torno de corridas de rua ilegais, assaltos e vários outros meios.");
			strcpy(filmes[2].nome, "Missão Impossível");
			filmes[2].nota = 7.1;
			filmes[2].ano = 1996;
			strcpy(filmes[2].sinopse, "Missão: Impossível é uma série de filmes de espionagem de ação americanos baseados em e uma continuação da série de televisão de mesmo nome criada por Bruce Geller. A série é produzida principalmente por e estrelado por Tom Cruise, cujo personagem é Ethan Hunt, um agente da Força de Missões Impossíveis.");
			strcpy(filmes[3].nome, "Senhor e Sra. Smith");
			filmes[3].nota = 6.5;
			filmes[3].ano = 2005;
			strcpy(filmes[3].sinopse, "John e Jane Smith aparentemente parecem formar um casal normal, mas na realidade ambos mantêm um segredo. Os dois são assassinos de aluguel contratados por empresas rivais. A verdade só vem à tona quando John e Jane, sem saber, recebem uma missão para eliminar o mesmo alvo e mais tarde descobrem que devem matar um ao outro.");
			strcpy(filmes[4].nome, "007 - Skyfall");
			filmes[4].nota = 7.7;
			filmes[4].ano = 2012;
			strcpy(filmes[4].sinopse, "Após uma missão mal sucedida de James Bond, a identidade de agentes secretos é revelada e o M16, atacado. Ajudado por um agente de campo, Bond deverá seguir a trilha de Silva, um homem que habita o passado de M e que tem contas a acertar.");
			strcpy(filmes[5].nome, "Kingsman");
			filmes[5].nota = 7.7;
			filmes[5].ano = 2021;
			strcpy(filmes[5].sinopse, "Um homem precisa correr contra o tempo para impedir que os piores tiranos e criminosos da história exterminem milhões de pessoas e destruam a humanidade.");
			strcpy(filmes[6].nome, "Megatubarão");
			filmes[6].nota = 5.6;
			filmes[6].ano = 2018;
			strcpy(filmes[6].sinopse, "Na fossa mais profunda do Oceano Pacífico, a tripulação de um submarino fica presa dentro do local depois de ser atacada por uma criatura pré-histórica que acreditavam estar extinta: um tubarão de mais de 20 metros de comprimento, o Megalodon.");
			strcpy(filmes[7].nome, "Resgate");
			filmes[7].nota = 6.7;
			filmes[7].ano = 2020;
			strcpy(filmes[7].sinopse, "Em Bangladesh, o mercenário do mercado negro Tyler Rake luta para sobreviver durante a missão para resgatar o filho sequestrado de um chefe do crime internacional.");
			printf("\n");
			for (int i =0; i<8;i++){
				printf("[%i] %s\n",i+1, filmes[i].nome);
			}

    }
    
    else if(opcao==2){
      printf("\nCada filme dessa categoria custa R$: 1.50");
			strcpy(filmes[0].nome, "O Rei Leão");
			filmes[0].nota = 8.5;
			filmes[0].ano = 1994;
			strcpy(filmes[0].sinopse, "Traído e exilado de seu reino, o leãozinho Simba precisa descobrir como crescer e retomar seu destino como herdeiro real nas planícies da savana africana.");
			strcpy(filmes[1].nome, "De Volta para o Futuro");
			filmes[1].nota = 8.5;
			filmes[1].ano = 1985;
			strcpy(filmes[1].sinopse, "Marty McFly, um adolescente de uma pequena cidade californiana, é transportado para a década de 1950 quando a experiência do excêntrico cientista Doc Brown dá errado. Viajando no tempo em um carro modificado, Marty conhece versões jovens de seus pais e precisa fazer com que eles se apaixonem, ou então ele deixará de existir.");
			strcpy(filmes[2].nome, "Vingadores");
			filmes[2].nota = 8.0;
			filmes[2].ano = 2012;
			strcpy(filmes[2].sinopse, "Loki ganha acesso ao poder ilimitado do cubo cósmico ao roubá-lo de dentro das instalações da S.H.I.E.L.D. Nick Fury, o diretor desta agência internacional que mantém a paz, logo reúne os únicos super-heróis que serão capazes de defender a Terra de ameaças sem precedentes.");
			strcpy(filmes[3].nome, "Pantera Negra");
			filmes[3].nota = 7.3;
			filmes[3].ano = 2018;
			strcpy(filmes[3].sinopse, "Conheça a história de T'Challa, príncipe do reino de Wakanda, que perde o seu pai e viaja para os Estados Unidos, onde tem contato com os Vingadores. Entre as suas habilidades estão a velocidade, inteligência e os sentidos apurados.");
			strcpy(filmes[4].nome, "Jurassic Park");
			filmes[4].nota = 8.1;
			filmes[4].ano = 1993;
			strcpy(filmes[4].sinopse, "Os paleontólogos Alan Grant, Ellie Sattler e o matemático Ian Malcolm fazem parte de um seleto grupo escolhido para visitar uma ilha habitada por dinossauros criados a partir de DNA pré-histórico. Após uma queda de energia, os visitantes descobrem, aos poucos, que vários predadores ferozes estão soltos e à caça.");
			strcpy(filmes[5].nome, "Piratas do Caribe");
			filmes[5].nota = 8.0;
			filmes[5].ano = 2003;
			strcpy(filmes[5].sinopse, "O capitão Salazar é a nova pedra no sapato do capitão Jack Sparrow. Ele lidera um exército de piratas fantasmas assassinos e está disposto a matar todos os piratas existentes na face da Terra. Para escapar, Sparrow precisa encontrar o Tridente de Poseidon, que dá ao seu dono o poder de controlar o mar.");
			strcpy(filmes[6].nome, "Dolittle");
			filmes[6].nota = 5.6;
			filmes[6].ano = 2020;
			strcpy(filmes[6].sinopse, "O Dr. Dolittle vive com uma variedade de animais exóticos e conversa com eles diariamente. Quando a jovem rainha Victoria fica doente, o excêntrico médico e seus amigos peludos embarcam em uma aventura épica em uma ilha mítica para encontrar a cura.");
			strcpy(filmes[7].nome, "Jumanji");
			filmes[7].nota = 7.0;
			filmes[7].ano = 1995;
			strcpy(filmes[7].sinopse, "Alan Parrish desapareceu quando era menino e ninguém acredita na história de seu amigo de que ele foi sugado por um jogo. Vinte e seis anos depois, duas crianças acham o jogo no sótão e, quando começam a jogar, Alan é libertado. Mas o jogo ainda não acabou e Alan precisa terminar antes de ser realmente libertado."); 
			printf("\n");
			for (int i =0; i<8;i++){
				printf("[%i] %s\n",i+1, filmes[i].nome);
			}
     
    }
    
    else if(opcao==3){
      printf("\nCada filme dessa categoria custa R$: 2.00");
				strcpy(filmes[0].nome, "O Auto da Compadecida");
				filmes[0].nota = 8.6;
				filmes[0].ano = 2000;
				strcpy(filmes[0].sinopse, "O filme mostra as aventuras de João Grilo e Chicó, dois nordestinos pobres que vivem de golpes para sobreviver. Eles estão sempre enganando o povo de um pequeno vilarejo no sertão da Paraíba, inclusive o temido cangaceiro Severino de Aracaju, que os persegue pela região. Somente a aparição da Nossa Senhora poderá salvar esta dupla.");
				strcpy(filmes[1].nome, "Esqueceram de mim");
				filmes[1].nota = 7.6;
				filmes[1].ano = 1990;
				strcpy(filmes[1].sinopse, "Home Alone é uma série de filmes de comédia familiar de Natal americana criada por John Hughes. Cada filme é dirigido individualmente por Chris Columbus, Raja Gosnell, Rod Daniel e Peter Hewitt.");
				strcpy(filmes[2].nome, "Monstros S.A.");
				filmes[2].nota = 8.1;
				filmes[2].ano = 2001;
				strcpy(filmes[2].sinopse, "A maior fábrica de monstros do mundo conta com James Sullivan, um dos monstros mais assustadores e seu assistente e melhor amigo Mike. Eles têm por missão assustar as crianças, que são consideradas tóxicas pelos monstros. Porém, ao visitar o mundo dos humanos, Mike e Sully conhecem a garota Boo, que acaba sem querer indo parar no mundo dos monstros.");
				strcpy(filmes[3].nome, "Ratatouille");
				filmes[3].nota = 8.0;
				filmes[3].ano = 2007;
				strcpy(filmes[3].sinopse, "Remy reside em Paris e possui um sofisticado paladar. Seu sonho é se tornar um chef de cozinha e desfrutar as diversas obras da arte culinária. O único problema é que ele é um rato. Quando se acha dentro de um dos restaurantes mais finos de Paris, Remy decide transformar seu sonho em realidade.");
				strcpy(filmes[4].nome, "As Branquelas");
				filmes[4].nota = 5.6;
				filmes[4].ano = 2004;
				strcpy(filmes[4].sinopse, "Dois irmãos agentes do FBI, Marcus e Kevin Copeland, acidentalmente evitam que bandidos sejam presos em uma apreensão de drogas. Como castigo, eles são forçados a escoltar um par de socialites nos Hamptons. Porém, quando as meninas descobrem o plano da agência, se recusam a ir. Sem opções, Marcus e Kevin decidem posar como as irmãs, transformando-se de homens afro-americanos em um par de loiras.");
				strcpy(filmes[5].nome, "Um senhor estagiário");
				filmes[5].nota = 7.1;
				filmes[5].ano = 2015;
				strcpy(filmes[5].sinopse, "Começar um novo emprego pode ser um grande desafio, especialmente para alguém aposentado. Tentando voltar ao mercado de trabalho, o viúvo Ben Whittaker, de 70 anos, aproveita a oportunidade para se tornar um estagiário sênior em um site de moda. Ben logo se torna popular entre seus colegas de trabalho mais jovens, incluindo Jules Ostin, a chefe e fundadora da empresa.");
				strcpy(filmes[6].nome, "Shazam");
				filmes[6].nota = 7.0;
				filmes[6].ano = 2019;
				strcpy(filmes[6].sinopse, "Billy Batson tem apenas 14 anos de idade, mas recebeu de um antigo mago o dom de se transformar em um super-herói adulto chamado Shazam. Ao gritar a palavra SHAZAM!, o adolescente se transforma nessa sua poderosa versão adulta para se divertir e testar suas habilidades. Contudo, ele precisa aprender a controlar seus poderes para enfrentar o malvado Dr. Thaddeus Sivana.");
				strcpy(filmes[7].nome, "Deadpool");
				filmes[7].nota = 8.0;
				filmes[7].ano = 2016;
				strcpy(filmes[7].sinopse, "Wade Wilson tem seu mundo destruído quando um cientista maligno o tortura e o desfigura completamente, ganhando poderes especiais de cura e uma força aprimorada. Com a ajuda de aliados poderosos e um senso de humor mais desbocado e cínico do que nunca, o anti-herói usa habilidades e métodos violentos para se vingar do homem que quase acabou com a sua vida.");
				printf("\n");
				for (int i =0; i<8;i++){
					printf("[%i] %s\n",i+1, filmes[i].nome);
				}

    }
    
    else if(opcao==4){
      printf("\nCada filme dessa categoria custa R$: 2.50");
			strcpy(filmes[0].nome, "Um Lugar Silencioso");
			filmes[0].nota = 7.5;
			filmes[0].ano = 2018;
			strcpy(filmes[0].sinopse, "Em uma fazenda nos Estados Unidos, uma família do Meio-Oeste é perseguida por uma entidade fantasmagórica assustadora. Para se protegerem, eles devem permanecer em silêncio absoluto, a qualquer custo, pois o perigo é ativado pela percepção do som.");
			strcpy(filmes[1].nome, "Garota Exemplar");
			filmes[1].nota = 8.1;
			filmes[1].ano = 2014;
			strcpy(filmes[1].sinopse, "No dia de seu quinto aniversário de casamento, Amy desaparece. Quando as aparências de uma união feliz começam a desmoronar, Nick, seu marido, torna-se o principal suspeito. Com a ajuda de sua irmã gêmea, ele tenta provar sua inocência, ao mesmo tempo em que investiga o que realmente aconteceu com a mulher.");
			strcpy(filmes[2].nome, "Nós");
			filmes[2].nota = 6.8;
			filmes[2].ano = 2019;
			strcpy(filmes[2].sinopse, "Adelaide e Gabe levam a família para passar um fim de semana na praia e descansar. Eles começam a aproveitar o ensolarado local, mas a chegada de um grupo misterioso muda tudo e a família se torna refém de seres com aparências iguais às suas.");
			strcpy(filmes[3].nome, "Corra!");
			filmes[3].nota = 7.7;
			filmes[3].ano = 2017;
			strcpy(filmes[3].sinopse, "Um jovem fotógrafo descobre um segredo sombrio quando conhece os pais aparentemente amigáveis da sua namorada.");
			strcpy(filmes[4].nome, "O Abutre");
			filmes[4].nota = 7.9;
			filmes[4].ano = 2014;
			strcpy(filmes[4].sinopse, "Para enfrentar dificuldades de conseguir um emprego formal, o jovem Louis Bloom decide entrar no agitado submundo do jornalismo criminal independente de Los Angeles. A fórmula é correr atrás de crimes e acidentes chocantes, registrar tudo e vender a história para veículos interessados.");
			strcpy(filmes[5].nome, "Animais Noturnos");
			filmes[5].nota = 7.5;
			filmes[5].ano = 2016;
			strcpy(filmes[5].sinopse, "Um escritor pede a sua ex-mulher para ler o manuscrito de seu novo romance, uma história sobre um homem de família cuja vida dá uma guinada sombria.");
			strcpy(filmes[6].nome, "Fragmentado");
			filmes[6].nota = 7.3;
			filmes[6].ano = 2016;
			strcpy(filmes[6].sinopse, "Kevin possui 23 personalidades distintas e consegue alterná-las quimicamente em seu organismo apenas com a força do pensamento. Um dia, ele sequestra três adolescentes que encontra em um estacionamento. Vivendo em cativeiro, elas passam a conhecer as diferentes facetas de Kevin e precisam encontrar algum meio de escapar.");
			strcpy(filmes[7].nome, "O Poço");
			filmes[7].nota = 7.0;
			filmes[7].ano = 2019;
			strcpy(filmes[7].sinopse, "O Poço conta a história de um lugar misterioso, uma prisão indescritível, um buraco profundo. Dois reclusos que vivem em cada nível. Um número desconhecido de níveis. Uma plataforma descendente contendo comida para todos eles.");
			printf("\n");
			for (int i =0; i<8;i++){
				printf("[%i] %s\n",i+1, filmes[i].nome);
			}
    }
    
    else if(opcao==5){
      printf("\nCada filme dessa categoria custa R$: 3.00");
			strcpy(filmes[0].nome, "Um Sonho de Liberdade");
			filmes[0].nota = 9.3;
			filmes[0].ano = 1994;
			strcpy(filmes[0].sinopse, "Andy Dufresne é condenado a duas prisões perpétuas consecutivas pelas mortes de sua esposa e de seu amante. Porém, só Andy sabe que ele não cometeu os crimes. No presídio, durante dezenove anos, ele faz amizade com Red, sofre as brutalidades da vida na cadeia, se adapta, ajuda os carcereiros, etc.");
			strcpy(filmes[1].nome, "Intocáveis");
			filmes[1].nota = 8.5;
			filmes[1].ano = 2011;
			strcpy(filmes[1].sinopse, "Um milionário tetraplégico contrata um homem da periferia para ser o seu acompanhante, apesar de sua aparente falta de preparo. No entanto, a relação que antes era profissional cresce e vira uma amizade que mudará a vida dos dois.");
			strcpy(filmes[2].nome, "Sempre ao Seu Lado");
			filmes[2].nota = 8.1;
			filmes[2].ano =  2009;
			strcpy(filmes[2].sinopse, "Professor universitário encontra na estação de trem um filhote de cachorro da raça Akita, conhecida por sua lealdade. O cão passa a acompanhá-lo até a estação de trem e esperar sua volta. Até que um acontecimento inesperado altera sua vida.");
			strcpy(filmes[3].nome, "O Resgate do Soldado Ryan");
			filmes[3].nota = 8.6;
			filmes[3].ano = 1998;
			strcpy(filmes[3].sinopse, "Ao desembarcar na Normandia, no dia 6 de junho de 1944, o Capitão Miller recebe a missão de comandar um grupo do Segundo Batalhão para o resgate do soldado James Ryan, o caçula de quatro irmãos, dentre os quais três morreram em combate. Por ordens do chefe George C. Marshall, eles precisam procurar o soldado e garantir o seu retorno, com vida, para casa.");
			strcpy(filmes[4].nome, "À Procura da Felicidade");
			filmes[4].nota = 8.0;
			filmes[4].ano = 2006;
			strcpy(filmes[4].sinopse, "Chris enfrenta sérios problemas financeiros e Linda, sua esposa, decide partir. Ele agora é pai solteiro e precisa cuidar de Christopher, seu filho de 5 anos. Chris tenta usar sua habilidade como vendedor para conseguir um emprego melhor, mas só consegue um estágio não remunerado.");
			strcpy(filmes[5].nome, "12 Anos de Escravidão");
			filmes[5].nota = 8.1;
			filmes[5].ano = 2013;
			strcpy(filmes[5].sinopse, "Em 1841, Solomon Northup é um negro livre, que vive em paz ao lado da esposa e filhos. Um dia, após aceitar um trabalho que o leva a outra cidade, ele é sequestrado e acorrentado. Vendido como se fosse um escravo, Solomon precisa superar humilhações físicas e emocionais para sobreviver.");
			strcpy(filmes[6].nome, "A Teoria de Tudo");
			filmes[6].nota = 7.7;
			filmes[6].ano = 2014;
			strcpy(filmes[6].sinopse, "Baseado na história de Stephen Hawking, o filme expõe como o astrofísico fez descobertas relevantes para o mundo da ciência, inclusive relacionadas ao tempo. Também retrata seu romance com Jane Wilde, uma estudante de Cambridge que viria a se tornar sua esposa.");
			strcpy(filmes[7].nome, "Creed: Nascido para Lutar");
			filmes[7].nota = 7.6;
			filmes[7].ano = 2015;
			strcpy(filmes[7].sinopse, "Adonis Johnson, filho do campeão de boxe Apollo Creed, pede a Rocky Balboa, que está aposentado, para ser seu treinador. Rocky aceita, mas tem dúvidas se Adonis tem o coração de um verdadeiro lutador.");
			printf("\n");
			for (int i =0; i<8;i++){
				printf("[%i] %s\n",i+1, filmes[i].nome);
			}

    }
    
    else if(opcao==6){
      printf("\nCada filme dessa categoria custa R$: 3.50");
			strcpy(filmes[0].nome, "Jogos Mortais");
			filmes[0].nota = 7.6;
			filmes[0].ano = 2004;
			strcpy(filmes[0].sinopse, "Dois homens acordam acorrentados em um banheiro como prisioneiros de um assassino em série que leva suas vítimas a situações limítrofes em um jogo macabro. Para sobreviver, eles terão de desvendar juntos as peças desse quebra-cabeças doentio.");
			strcpy(filmes[1].nome, "Invocação do Mal");
			filmes[1].nota = 7.5;
			filmes[1].ano = 2013;
			strcpy(filmes[1].sinopse, "Os investigadores paranormais Ed e Lorraine Warren trabalham para ajudar a família aterrorizada por uma entidade demoníaca em sua fazenda.");
			strcpy(filmes[2].nome, "Chucky");
			filmes[2].nota = 6.6;
			filmes[2].ano = 1988;
			strcpy(filmes[2].sinopse, "Karen presenteia seu filho pequeno, Andy, com um boneco muito especial. Os dois precisam lutar por suas vidas, porém, quando crimes estranhos começam a acontecer pela vizinhança, revelando a natureza sombria do brinquedo.");
			strcpy(filmes[3].nome, "It a coisa");
			filmes[3].nota = 7.3;
			filmes[3].ano = 2017;
			strcpy(filmes[3].sinopse, "Um grupo de crianças se une para investigar o misterioso desaparecimento de vários jovens em sua cidade. Eles descobrem que o culpado é Pennywise, um palhaço cruel que se alimenta de seus medos e cuja violência teve origem há vários séculos.");
			strcpy(filmes[4].nome, "Anabelle");
			filmes[4].nota = 5.4;
			filmes[4].ano = 2014;
			strcpy(filmes[4].sinopse, "John Form acha que encontrou o presente ideal para sua esposa grávida, uma boneca vintage. No entanto, a alegria do casal não dura muito. Uma noite terrível, membros de uma seita satânica invadem a casa do casal em um ataque violento. Ao tentarem invocar um demônio, eles mancham a boneca de sangue, tornando-a receptora de uma entidade do mal.");
			strcpy(filmes[5].nome, "A freira");
			filmes[5].nota = 5.3;
			filmes[5].ano = 2018;
			strcpy(filmes[5].sinopse, "Presa em um convento na Romênia, uma freira comete suicídio. Para investigar o caso, o Vaticano envia um padre assombrado e uma noviça prestes a se tornar freira. Arriscando suas vidas, a fé e até suas almas, os dois descobrem um segredo profano e se confrontam com uma força do mal que toma a forma de uma freira demoníaca e transforma o convento em um campo de batalha.");
			strcpy(filmes[6].nome, "Doutor Sono");
			filmes[6].nota = 7.3;
			filmes[6].ano = 2019;
			strcpy(filmes[6].sinopse, "Na infância, Danny Torrance sobreviveu a uma tentativa de homicídio por parte do pai. Já adulto, sua paz, porém, está com os dias contados a partir de quando cria um vínculo telepático com Abra, uma menina com poderes tão fortes quanto aqueles que ele bloqueia dentro de si.");
			strcpy(filmes[7].nome, "Cadáver");
			filmes[7].nota = 5.1;
			filmes[7].ano = 2020;
			strcpy(filmes[7].sinopse, "Um exorcismo chocante sai do controle e ceifa a vida de uma jovem mulher. Meses depois, a policial Megan Reed está trabalhando no necrotério de um hospital quando recebe um cadáver desfigurado. Trancada e sozinha dentro dos corredores do porão, Megan experimenta visões horripilantes e começa a suspeitar que o corpo pode estar possuído por uma força demoníaca impiedosa.");
			printf("\n");
			for (int i =0; i<8;i++){
				printf("[%i] %s\n",i+1, filmes[i].nome);
			}
		}
}

void detalhesDoFilme (int opcao){
    //Aparece detalhes do filme
		struct listaFilmes filme[100];
		printf("\nNome: %s \nAno de Lançamento: %d\nNota no IMDb: %.2lf/10\n",filme[opcao-1].nome, filme[opcao-1].ano, filme[opcao-1].nota);
		printf("Sinopse: \n%s\n",filme[opcao-1].sinopse);
		
}

char matriz_itens[48][100]; 

void adicionarCarrinho(int codigoFilme){
  struct listaFilmes filme[100];
  strcpy(matriz_itens[contador], filme[opcao-1].nome); 
  
  printf("Adicionado ao carrinho: %s\n", filme[opcao-1].nome);
}

float preco[48];
void removerCarrinho(int codigoFilme){
    for(int i = codigoFilme-1; i<contador;i++){
      strcpy(matriz_itens[i], matriz_itens[i+1]);
      preco[i]=preco[i+1];
    }
    contador-=1; 
		
}

void precoCarrinho(int genero) {
  if (genero==1){
    preco[contador]=1;
  }
  else if (genero==2){
    preco[contador]=1.5;
    }
  else if (genero==3){
    preco[contador]=2;
    }
  else if (genero==4){
    preco[contador]=2.5;
    }
  else if (genero==5){
    preco[contador]=3;
    }
  else if (genero==6){
    preco[contador]=3.5;
    }
}

void subtotalCompra(int opcao){
    float total=0;
    printf("\nItens em seu carrinho:\n");
    for (int i =0; i<contador;i++){
      printf("[%d]", i+1);
      printf("%s", matriz_itens[i]);
      printf("  - valor: R$ %.2f\n", preco[i]);
    } printf("\n");
    for (int i =0; i<contador;i++){
      total=total+preco[i];
    }
    printf("Valor total da compra: R$%.2f\n", total);
    
    if(opcao==2){
      printf("Sua compra foi finalizada com sucesso!\n");
    }
}

void limparCarrinho(int codigoFilme){
  while (contador!=0){
    for(int i=codigoFilme-1; i<contador;i++){
      strcpy(matriz_itens[i], matriz_itens[i+1]);
    }
    contador-=1;
  } 
}