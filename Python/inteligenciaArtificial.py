import tensorflow as tf
import numpy as np


def dataConvert(data):
    try:
        data = float(data)
        return True  # Convierto el dato a un float
    except:
        print("No es un valor esperado\n")
        return False  # Si tira error la conv. devuelvo un false


pulgadas = np.array([0.393701, 196.85, 393.701, 787.4016,
                    1181.102, 2362.205, 3937.008, 19685.039], dtype=float)
centimetros = np.array(
    [1, 500, 1000, 2000, 3000, 6000, 10000, 50000], dtype=float)


capa = tf.keras.layers.Dense(units=1, input_shape=[1])
modelo = tf.keras.Sequential([capa])

modelo.compile(
    optimizer=tf.keras.optimizers.Adam(0.1),
    loss='mean_squared_error'
)

print("Entrenando..!")

historial = modelo.fit(centimetros, pulgadas, epochs=1000, verbose=False)

numVer = False
while numVer == False:  # Hasta que el peso no sea valido va a seguir pidiendolo
    num = input("Ingrese los centimetros que desea convertir: ")
    numVer = dataConvert(num)


numDef = float(num)

resultado = modelo.predict([numDef])
res = float(resultado)
print(f"{num} centimetros son {res} en pulgadas")
