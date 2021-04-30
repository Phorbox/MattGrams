/**
 * 
 */
package application.model;

/**
 * @author dabox
 *
 */
public class Cast {

	/**
	 * 
	 */
	
	String Name;
	String Actor;
	String Role;
	String Nationality;
	public Cast(String newName, String newActor, String newRole, String newNationality) {
		this.Name = newName;
		this.Actor = newActor;
		this.Role = newRole;
		this.Nationality = newNationality;
	}
	
	
	
	public String toString() {

		return String.format("\t- %s %s, %s (%s)", this.Role, this.Name, this.Actor, this.Nationality);
	}
}
