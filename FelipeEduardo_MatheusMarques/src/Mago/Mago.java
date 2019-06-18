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
		System.out.println("O Mago " + getNome() + " est� invisivel.");
	}
	public void ultraRapidez(){
		System.out.println("O Mago " + getNome() + " est� utra r�pido.");
	}
	public void andar(){
		System.out.println("O Mago " + getNome() + " est� andando.");
	}
	public void usarItem(){
		System.out.println("O Mago " + getNome() + " utilizou um item.");
	}
	public void guardarItem(){
		System.out.println("O Mago " + getNome() + " guardou um item.");
	}
}

