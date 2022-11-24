from os import system;
import smtplib

def emailVerify(email):
    while email.__contains__("@") == False or email.__contains__(".") == False:#verifico que el email contega @ y .algo
        _ = system("cls")
        email = input("Ingrese un email valido: ")
    return email #Cuando ingrese un email valido lo devuelvo

def dataConvert(data):
    try:
        data = float(data) #Convierto el dato a un float
    except:
        return False, data #Si tira error la conv. devuelvo un false
    return True, data #Si no hay error devuelvo un True

def intVerify(weight,height):
    #convierto los datos a flotante
    weightVer,weight = dataConvert(weight)
    heightVer,height = dataConvert(height)

    while weightVer == False: #Hasta que el peso no sea valido va a seguir pidiendolo
        _ = system("cls")
        weight = input("Ingrese un peso valido: ")
        weightVer,weight = dataConvert(weight)

    while heightVer == False: #Hasta que la altura no sea valida va a seguir pidiendola
        _ = system("cls")
        height = input("Ingrese una altura valida: ")
        heightVer,height = dataConvert(height)
        
    return weight, height #Cuando la altura y el peso sean validos los devuelvo

def imcCal(height,weight):
    #Calculo el IMC y muestro el mensaje correspondiente
    indexIMC = weight/height**2
    indexIMC = round(indexIMC,1)
    _ = system("cls")
    print("Calculando el IMC...")
    if indexIMC < 18.5: 
        print("USTED ESTA DEBAJO DE SU PESO")
        indexIMC
    elif indexIMC > 18.5 and indexIMC < 24.9:
        print("USTED ESTA EN SU PESO NORMAL")
        return indexIMC
    elif indexIMC > 25 and indexIMC < 29.9:
        print("USTED TIENE SOBREPESO")
        return indexIMC
    else:
        print("USTED TIENE OBESIDAD")
        return indexIMC    

def getData():
    data = {}
    mask = ["height","weight","email"] #Creo un array que contiene los datos que quiero pedirle al usuario
    
    for p in mask: 
        data[p] = input(f"Ingrese su {p}: ") #Pido los datos y los guardo en el diccionario
    
    data["email"] = emailVerify(data["email"]) #Verifico que el email sea valido, y si lo es lo guardo
    data["weight"], data["height"] = intVerify(data["weight"],data["height"]) #Verifico que el peso y la altura sean 
                                                                              #validos y si los son los guardo

    return data["height"], data["weight"],data["email"] #Devuelvo el peso, la altura y el email ya verificados

def emailSender(email,height,weight,imc):
    server = smtplib.SMTP(host = "smtp.gmail.com", port = 587)
    #Paso los datos a string para mandarlos en un mensaje
    height = str(height)
    weight = str(weight)
    imc = str(imc)

    server.ehlo()
    print("--- ENVIANDO MAIL CON SU INFORMACION... ---")
    # mensaje = f""" 
    # Su peso es {weight}"""
    mensaje = "Subject: CALCULADORA DE IMC \n" + "Su peso es " + weight+"Kg " +" Su altura es " + height +"m "+"Su IMC es " + imc
    # Saco los espacios dentro del email
    email = email.strip()
    #Inicio la conexión
    server.starttls()
    #logeo el email con el cual mando el main y mando el mail hacia la direccion del usuario
    server.login(user="imc.results.no.answer@gmail.com", password="imcresultsashe")
    try:
        server.sendmail(from_addr="imc.results.no.answer@gmail.com", 
        to_addrs=email, msg=mensaje)
    except:
        print("Ocurrio un error al mandar el mail")
        server.quit()
        return False
    print("Se ha enviado el email con sus datos")
    return True

    

def init():
    print("-------bienvenido a la calculadora de IMC--------")
    print("Porfavor ingrese el peso en kg y la altura en m")
    
    height,weight,email = getData() #Guardo los datos necesarios ya verificados
    print(height)
    imc = imcCal(height,weight) #Calculo el IMC pasandole la altura y el peso ya verificados
    
    sended = emailSender(email,height,weight,imc)

    while sended == False:
        sended = emailSender(email,height,weight,imc)
        email = input("Por favor ingrese su mail nuevamente")

    print("------- Muchas gracias por usar la calculadora de IMC -------")
    

init() #Inicio el programa


