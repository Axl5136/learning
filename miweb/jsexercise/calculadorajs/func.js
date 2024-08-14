function limpiadito(){
    document.getElementById("miformulario").reset();
    
}
function sumar(){
    var x = parseInt(document.getElementById("valor1").value);
    var y = parseInt(document.getElementById("valor2").value);
    document.getElementById("resultado").innerHTML = x+y;
}
function restar(){
    var x = parseInt(document.getElementById("valor1").value);
    var y = parseInt(document.getElementById("valor2").value);
    if(x<y){
        alert("no existen resultados negativos.")
        document.getElementById('resultado').innerHTML ="Error";
        
    }else 
    {
        document.getElementById('resultado').innerHTML = x-y;
        
    }

    
}
function multiplicar(){
    var x = parseInt(document.getElementById("valor1").value);
    var y = parseInt(document.getElementById("valor2").value);
    document.getElementById("resultado").innerHTML = x*y;
    
}
function dividir(){
    var x = parseInt(document.getElementById("valor1").value);
    var y = parseInt(document.getElementById("valor2").value);
    document.getElementById("resultado").innerHTML = x/y;
}