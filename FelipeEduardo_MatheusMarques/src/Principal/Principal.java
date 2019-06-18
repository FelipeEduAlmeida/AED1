package Principal;
import java.util.ArrayList;
import Cavaleiro.Cavaleiro;
import Mago.Mago;
import Dragao.Dragao;
import Jogo.Jogo;
import Personagem.Personagem;

public class Principal{
	

	
	public static void main(String[] args){
		ArrayList<Personagem> personagens = new ArrayList<Personagem>();
		
		Cavaleiro cv1 = new Cavaleiro("Fabio");
		Cavaleiro cv2 = new Cavaleiro("José");
		Mago mg1 = new Mago("Harry Potter");
		Mago mg2 = new Mago("Gandalf");
		Dragao dg1 = new Dragao("Smaug");
		Dragao dg2 = new Dragao("Shen Long");
		
		personagens.add(cv1);
		personagens.add(cv2);
		personagens.add(mg1);
		personagens.add(mg2);
		personagens.add(dg1);
		personagens.add(dg2);
		
		Jogo jogo = new Jogo();
		
		jogo.executaAcoesComuns(personagens.get(0));
		jogo.executaAcoesComuns(personagens.get(1));
		jogo.executaAcoesComuns(personagens.get(2));
		jogo.executaAcoesComuns(personagens.get(3));
		jogo.executaAcoesComuns(personagens.get(4));
		jogo.executaAcoesComuns(personagens.get(5));
		
		Personagem p;
		p =  new Mago("Merlin");
		((Mago) p).invisibilidade();
		
	}
}
