package Cavaleiro;
import Personagem.Personagem;
import ComportamentoHeroico.ComportamentoHeroico;

public class Cavaleiro extends Personagem implements ComportamentoHeroico{

	public Cavaleiro(String nome) {
		super(nome);
	}
	public void atacar(){
		System.out.println("O Cavaleiro " + getNome() + " está atacando.");
	}
	public void defender(){
		System.out.println("O Cavaleiro " + getNome() + " está se defendendo.");
	}
	public void saltar(){
		System.out.println("O Cavaleiro " + getNome() + " está saltando.");
	}
	public void andar(){
		System.out.println("O Cavaleiro " + getNome() + " está andando.");
	}
	public void usarItem(){
		System.out.println("O Cavaleiro " + getNome() + " utilizou um item.");
	}
	public void guardarItem(){
		System.out.println("O Cavaleiro " + getNome() + " guardou um item.");
	}
}
