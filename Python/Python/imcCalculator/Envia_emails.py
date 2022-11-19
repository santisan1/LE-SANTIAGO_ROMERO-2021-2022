from os import system
import smtplib
from email.message import EmailMessage


def emailSender(email):
    server = smtplib.SMTP(host="smtp.gmail.com", port=587)
    print("--- ENVIANDO MAIL CON SU INFORMACION... ---")

    message = EmailMessage()
    with open('Cuerpo_email.html', 'r') as file:
        file_content = file.read()
    message.set_content(file_content, subtype='html')

    email = email.strip()

    message['Subject'] = "email_subject"
    message['From'] = "pruebaphyton3@gmail.com"
    message['To'] = email
    server.ehlo()

    server.starttls()

    server.login(user="pruebaphyton3@gmail.com",
                 password="rvqzjrfcnoiregcy")

    server.send_message(message)

    print("Se ha enviado el mail")

    server.quit()


emailSender()
