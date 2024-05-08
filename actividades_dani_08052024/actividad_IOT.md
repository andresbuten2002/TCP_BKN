# Sistema de Monitoreo de IoT con MQTT, Node-RED, InfluxDB, Grafana y Home Assistant.

## Resumen



El proyecto tiene como objetivo desarrollar un sistema completo de monitoreo de IoT que capture y almacene los datos de temperatura y uso de CPU de servidores, y proporcione visualizaciones en tiempo real y automatización a través de diferentes componentes. Se utilizarán tecnologías como MQTT, Node-RED del lado del servidor y python y bash del lado de los clientes.

Objetivo general: Implementar un sistema integral de monitoreo de IoT que permita capturar, almacenar y visualizar los datos de temperatura y uso de CPU de servidores,



## Milestone 1: Despliegue de Node-RED y EMQX como servicios

1. Configurar el entorno de Docker y Docker Compose.
2. Crear un archivo `docker-compose.yml` para definir los servicios de Node-RED y EMQX.
3. Configurar el servicio de Node-RED en Docker Compose, especificando los volúmenes, puertos y dependencias necesarios.
4. Configurar el servicio de EMQX en Docker Compose, especificando los volúmenes, puertos y configuraciones necesarias.
5. Ejecutar `docker-compose up` para desplegar los contenedores de Node-RED y EMQX.


### docker mosquitto
- probar (hecha por mi): docker run -it -v /etc/mosquitto/mosquitto.conf:/etc/mosquitto/mosquitto.conf -p 1883:1883 -d mosquitto:1.0
https://cedalo.com/blog/mosquitto-docker-configuration-ultimate-guide/
### docker node-red
https://nodered.org/docs/getting-started/docker

### docker emqx 
https://www.emqx.io/docs/en/latest/deploy/install-docker.html
CAMBIAMOS PUERTO 1883->>1884 para que no se superonga con mosquitto
> docker run -d --name emqx -p 1884:1884 -p 8083:8083 -p 8084:8084 -p 8883:8883 -p 18083:18083  emqx:5.6.1 




## Milestone 2: Aprovisionamiento de configuraciones

1. Configurar las credenciales y configuraciones específicas de Node-RED, como la configuración de conexión a EMQX y otros nodos necesarios.
2. Aprovisionar los archivos de configuración necesarios para EMQX, como los archivos de configuración general, autenticación y tópicos MQTT.
3. Reiniciar los contenedores de Node-RED y EMQX para aplicar las nuevas configuraciones.

## Milestone 3: Creación del cliente Bash

1. Crear un archivo Bash que utilice el comando `lm-sensors` para obtener la información de temperatura y uso de CPU.
2. Configurar el cliente Bash para publicar los datos obtenidos en un tópico MQTT específico en el broker EMQX.

## Milestone 4: Creación del cliente Python

1. Crear un script en Python que utilice la librería Paho para conectarse al broker EMQX.
2. Implementar la lógica necesaria para obtener la información de temperatura y uso de CPU utilizando `lm-sensors`.
3. Configurar el cliente Python para publicar los datos obtenidos en un tópico MQTT específico en el broker EMQX.

Cada milestone representa un hito importante en el proceso de despliegue y configuración. Al completar estos milestones, habrás desplegado Node-RED y EMQX como servicios, aprovisionado sus configuraciones y creado los clientes Bash y Python para enviar la información de lm-sensors al broker MQTT.

### Pasos previos
1. Instalar libreria mqtt para python:
```shell
pip install --user paho-mqtt
```


### QoS
El QoS (Quality of Service o Calidad de Servicio) en MQTT (Message Queuing Telemetry Transport) es un mecanismo que garantiza la entrega confiable de mensajes entre el cliente y el servidor (broker). El QoS especifica el nivel de garantía que se proporciona con respecto a la entrega de un mensaje. Hay tres niveles de QoS en MQTT:

- QoS 0 (At most once): Este es el nivel de QoS más bajo. El mensaje se entrega al menos una vez o nunca. No hay garantía de entrega, ya que el mensaje se envía sin confirmación y se entrega de manera "lo más seguro posible". Este nivel de QoS es el más rápido y menos confiable.
- QoS 1 (At least once): En este nivel de QoS, el mensaje se entrega al menos una vez. Si el mensaje no se entrega correctamente (por ejemplo, si se pierde durante la transmisión), el cliente lo volverá a enviar hasta que reciba una confirmación de entrega del servidor. Esto garantiza que no se pierdan mensajes, pero puede resultar en duplicados.
- QoS 2 (Exactly once): Este nivel de QoS proporciona la entrega exactamente una vez. Se realiza un intercambio de confirmación de cuatro pasos entre el cliente y el servidor para garantizar que el mensaje se entregue solo una vez. Este nivel de QoS es el más lento pero el más confiable, ya que garantiza que no haya duplicados ni pérdidas.