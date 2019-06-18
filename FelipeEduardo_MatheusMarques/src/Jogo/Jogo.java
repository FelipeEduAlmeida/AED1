package Jogo;
import Personagem.Personagem;

public class Jogo {

	public Jogo() {
	
	}
	public void executaAcoesComuns(Personagem tipoPersonagem){
		tipoPersonagem.andar();
		tipoPersonagem.usarItem();
		tipoPersonagem.guardarItem();
	}
}
