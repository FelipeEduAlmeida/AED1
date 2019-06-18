package Dragao;
import Personagem.Personagem;

public class Dragao extends Personagem {

	public Dragao(String nome) {
		super(nome);
	}
	
	public void atirarFogo(){
		System.out.println("O Dragao " + getNome() + " atirou fogo.");
	}
	
	public void voar(){
		System.out.println("O Dragao " + getNome() + " está voando.");
	}
	
	public void morder(){
		System.out.println("O Dragao " + getNome() + " mordeu.");
	}
	
	public void andar(){
		System.out.println("O Dragao " + getNome() + " está andando.");
	}
	public void usarItem(){
		System.out.println("O Dragao " + getNome() + " utilizou um item.");
	}
	public void guardarItem(){
		System.out.println("O Dragao " + getNome() + " guardou um item.");
	}
}
