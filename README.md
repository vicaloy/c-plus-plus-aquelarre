# 🧙‍♀️ Sistema de Gestión del Aquelarre en C++

Este proyecto es un sistema diseñado para gestionar la información de un aquelarre de brujas, permitiendo registrar brujas supremas y comunes, gestionar hechizos, y obtener listados detallados. Se aplica una arquitectura en capas con una clase Fachada para la gestión de la lógica del sistema.

## 🛠️ Requerimientos Técnicos

- Principio de separación en capas:
El sistema está organizado en capas lógicas separadas para garantizar una arquitectura modular y fácil de mantener.

- Clase Fachada:
Proporciona una interfaz única para acceder a la lógica del sistema, facilitando la interacción con las distintas capas.

- Evitar duplicación de información:
Se utilizan punteros a objetos para evitar redundancias y optimizar la gestión de datos.
