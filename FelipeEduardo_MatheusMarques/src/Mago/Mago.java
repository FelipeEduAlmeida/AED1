package Mago;
import Personagem.Personagem;
import ComportamentoMagico.ComportamentoMagico;

public class Mago extends Personagem implements ComportamentoMagico{

	public Mago(String nome) {
		super(nome);
	}
	
	public String getNome() {
		return super.getNome();
	}
	public void setNome(String nome) {
		super.setNome(nome);
	}
	
	public void invisibilidade(){
		System.out.println("O Mago " + getNome() + " está invisivel.");
	}
	public void ultraRapidez(){
		System.out.println("O Mago " + getNome() + " está utra rápido.");
	}
	public void andar(){
		System.out.println("O Mago " + getNome() + " está andando.");
	}
	public void usarItem(){
		System.out.println("O Mago " + getNome() + " utilizou um item.");
	}
	public void guardarItem(){
		System.out.println("O Mago " + getNome() + " guardou um item.");
	}
}

