import paho.mqtt.publish as publish

broker_address = "localhost"
topic = "casa/cocina/heladera"
publish.single(topic, "{ temp:30 }", hostname=broker_address,
client_id='bocha_pub.py')