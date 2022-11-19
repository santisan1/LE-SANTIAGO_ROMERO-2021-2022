from concurrent.futures.process import _global_shutdown
import re
import os
import smtplib
from email.message import EmailMessage
from string import Template


# sobreescribimos los datos obtenidos de python en la plantilla
def enviodatos(dict, nombre, imc):
    filein = open("Cuerpo_email.html")
    src = Template(filein.read())
    result = src.substitute(dict)
    try:
        os.mkdir(f"Registros/IMCResults{nombre}{imc}")
        filein2 = open(
            f"Registros/IMCresults{nombre}{imc}/IMCresults{nombre}{imc}"+".html", "a")
        filein2.write(result)
    except:
        if os.path.exists(f"Registros/IMCresults{nombre}{imc}"):
            filein2 = open(
                f"Registros/IMCresults{nombre}{imc}/IMCresults{nombre}{imc}"+".html", "a")
            filein2.write(result)


def emailSender(email, nombre, imc):  # Función para enviar mail // mandamos el newhtml
    server = smtplib.SMTP(host="smtp.gmail.com", port=587)
    print("--- ENVIANDO MAIL CON SU INFORMACION... ---")
    message = EmailMessage()

    with open(f'Registros/IMCresults{nombre}{imc}/IMCresults{nombre}{imc}.html', 'r') as file:
        file_content = file.read()
    message.set_content(file_content, subtype='html')

    email = email.strip()

    message['Subject'] = "Resultados IMC"
    message['From'] = "imc.results.no.answer@gmail.com"
    message['To'] = email
    server.ehlo()

    try:
        server.starttls()

        server.login(user="imc.results.no.answer@gmail.com",
                     password="vqqetlzrcihscbmz")

        server.send_message(message)

        print(f"Se ha enviado el mail correctamente a {email}")

        server.quit()
    except:
        print("ocurrió un error al enviar el correo")


def clearScreen():
    os.system('cls')


def verifymail(mail):  # verificamos el mail
    clearScreen()
    valido = True
    mailtocheck = re.compile(
        r"^[A-Za-z0-9\.\+_-]+@[A-Za-z0-9\._-]+\.[a-zA-Z]*$")
    if not mailtocheck.match(mail):
        valido = False
    else:
        valido = True
    if valido == 0:
        mail = str(input("\nMail invalido, intente otra vez: "))
        verifymail(mail)
    else:
        print(f"\nLos resultados llegaran a {mail} con éxito")


def calculoimc(Altura, Peso, nombre):
    clearScreen()
    altura = float(Altura)
    peso = float(Peso)
    pasaje = float(altura/100)
    newhigh = float(pasaje*pasaje)
    imc = float(peso/newhigh)

    imc2 = round(imc, 2)
    if imc < 18.50:
        resultados = "Bajo de peso"
    elif imc <= 24.90:
        resultados = "Peso normal"
    elif imc <= 29.9:
        resultados = "Sobre peso"
    elif imc <= 34.9:
        resultados = "Obesidad tipo I"
    elif imc <= 39.9:
        resultados = "Obesidad tipo II"
    elif imc >= 40:
        resultados = "Obesidad tipo III"
    print(f"{nombre}, su imc es de {imc2} y está en {resultados}")

    return imc2, resultados


def comprobacion_valoresstr(name):
    try:
        name = float(name)
        clearScreen()
        print("Se espera una letra al menos.")
        return 0
    except:
        return 1


def comprobacion_valoresif(name):
    try:
        name = float(name)

        return 0
    except:
        clearScreen()
        print("Ingrese el tipo de caracter pedido")
        return 1


def inicio_de_session():
    clearScreen()
    cntr = 0

    while cntr == 0:
        Nombre = input("Buenas tardes, ingrese su nombre: ")
        cntr = comprobacion_valoresstr(Nombre)
    nombre = Nombre.capitalize()

    while cntr == 1:
        edad = input(f"\nHola {nombre}, ¿Cuántos años tienes? ")
        cntr = comprobacion_valoresif(edad)
    cntr = 1
    while cntr == 1:
        Peso = input(
            f"\nCon que {edad} años, perfecto. ¿Cuál es tu peso(kg)? ")
        cntr = comprobacion_valoresif(Peso)
    cntr = 1
    while cntr == 1:
        Altura = input("\nYa para terminar, ¿Cuánto mides(cm)? ")
        cntr = comprobacion_valoresif(Altura)

    imc2, result = calculoimc(Altura, Peso, nombre)

    n = input("\n¿Cuántas veces a la semana se ejercita? (ingresar entero)")

    if n == 0:
        print(
            f"\nDebería hacer más deporte {nombre} pero no importa, sigamos...")
        deportes = ["No realiza deportes"]
    else:
        deportes = []
        print(f"\n¡Excelente, {nombre}!")
        j = int(input(
            "\nPara saber más, ¿Cúantos deportes o actividades haces? (ingresar entero) "))
        for i in range(j):
            deporte = input("Deporte:")
            deportes.append(deporte)

    Registro = {"Nombre": nombre, "Edad": edad, "Altura": Altura, "Peso": Peso, "Ejercitacion_por_semana": n,
                "Deporte_s": deportes, "imc2": imc2, "Condicion": result, "charset": "Charset=UTF-8"}
    enviodatos(Registro, nombre, imc2)

    rta = int(input(
        f"\nEso es todo {nombre}, ¿Desea que le enviemos los resultados por mail o verlos impresos? (Mail:1/Imp:2/Ambas:3)"))

    if rta == 1:
        mail = str(input("\nPerfecto, ingrese su mail por favor: "))
        verifymail(mail)
        emailSender(mail, nombre, imc2)
    elif rta == 2:
        impresion(Registro)

    elif rta == 3:
        impresion(Registro)
        mail = str(input("\nPerfecto, ingrese su mail por favor: "))
        verifymail(mail)
        emailSender(mail, nombre, imc2)


def impresion(dict):
    clearScreen()
    impr = ["Nombre", "Edad", "imc2", "Condicion",
            "Ejercitacion_por_semana", "Deporte_s"]
    for i in impr:
        print(f"{i}: {dict[i]}")


def default():
    print('''
              |       Introducción a Phyton         |
              |-------------------------------------|
              |-------------------------------------|
              |                 TP 1                |
              |-------------------------------------|
              | 1. Logearse     e     Imprimir ↵    |
              |-------------------------------------|''')

    cntr = 1
    j = 0
    while cntr == 1 and j != 1:
        j = input("Ingrese 1 para comenzar :) ")
        cntr = comprobacion_valoresif(j)

    inicio_de_session()


default()
