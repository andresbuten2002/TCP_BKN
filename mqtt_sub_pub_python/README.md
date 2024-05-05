# Pasos previos
1. Instalar libreria mqtt para python:
```shell
pip install --user paho-mqtt
```


## QoS
El QoS (Quality of Service o Calidad de Servicio) en MQTT (Message Queuing Telemetry Transport) es un mecanismo que garantiza la entrega confiable de mensajes entre el cliente y el servidor (broker). El QoS especifica el nivel de garantía que se proporciona con respecto a la entrega de un mensaje. Hay tres niveles de QoS en MQTT:

- QoS 0 (At most once): Este es el nivel de QoS más bajo. El mensaje se entrega al menos una vez o nunca. No hay garantía de entrega, ya que el mensaje se envía sin confirmación y se entrega de manera "lo más seguro posible". Este nivel de QoS es el más rápido y menos confiable.
- QoS 1 (At least once): En este nivel de QoS, el mensaje se entrega al menos una vez. Si el mensaje no se entrega correctamente (por ejemplo, si se pierde durante la transmisión), el cliente lo volverá a enviar hasta que reciba una confirmación de entrega del servidor. Esto garantiza que no se pierdan mensajes, pero puede resultar en duplicados.
- QoS 2 (Exactly once): Este nivel de QoS proporciona la entrega exactamente una vez. Se realiza un intercambio de confirmación de cuatro pasos entre el cliente y el servidor para garantizar que el mensaje se entregue solo una vez. Este nivel de QoS es el más lento pero el más confiable, ya que garantiza que no haya duplicados ni pérdidas.