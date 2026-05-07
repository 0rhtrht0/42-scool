use std::env;

fn additionner(a: i32, b: i32) -> i32 {
    a + b
}

fn main() {
    // Récupère les arguments passés en ligne de commande
    let args: Vec<String> = env::args().collect();

    // Vérifie si on a assez d'arguments (le 1er est toujours le nom du programme)
    if args.len() < 3 {
        println!("Usage: {} <nombre1> <nombre2>", args[0]);
        return;
    }

    // On transforme les chaînes de caractères en entiers (i32)
    let num1: i32 = args[1].parse().expect("Le premier argument doit être un nombre");
    let num2: i32 = args[2].parse().expect("Le deuxième argument doit être un nombre");

    let resultat = additionner(num1, num2);

    println!("La somme de {} et {} est {}", num1, num2, resultat);
}