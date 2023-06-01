/*
 * Proyecto AdministradorEscuela
 * Angel Mauricio Ramirez Herrera
 * A01710158
 * 24/05/2023
 */

/*
 * Clase Escuela es una clase
 * que permite administrar los datos
 * con respecto a las personas
 * que se encuentran registradas
 * en una escuela
 */

#ifndef ESCUELA_H_
#define ESCUELA_H_

#include "Administrativo.h"
#include "Alumno.h"
#include "Persona.h"
#include "Profesor.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Escuela {
private:
  // Variables iniciales
  string nombre;
  string direccion;
  string telefono;
  vector<Persona *> personas;

public:
  // Constructor
  Escuela() {}
  Escuela(string nombre, string direccion, string telefono);

  // Getters
  string get_nombre();
  string get_direccion();
  string get_telefono();

  // Setters
  void set_nombre(string);
  void set_direccion(string);
  void set_telefono(string);
  Alumno *get_alumno(string);
  Profesor *get_profesor(string, string);
  Administrativo *get_administrativo(string, string);

  // Metodos
  void show_personas();
  void agregar_alumno(string, int, string, string, string);
  void agregar_profesor(string, int, string, string, string);
  void agregar_administrativo(string, int, string, string, string);
};

// Constructor

Escuela::Escuela(string nombre, string direccion, string telefono) {
  this->nombre = nombre;
  this->telefono = telefono;
  this->direccion = direccion;
}

// Getters

string Escuela::get_nombre() { return nombre; };

string Escuela::get_direccion() { return direccion; };

string Escuela::get_telefono() { return telefono; };

Alumno *Escuela::get_alumno(string matricula) {
  for (Persona *persona : personas) {
    if (dynamic_cast<Alumno *>(persona)->get_matricula() == matricula) {
      return dynamic_cast<Alumno *>(persona);
    }
  }
  return nullptr; // El alumno no se encontró
}

Profesor *Escuela::get_profesor(string nombre, string especialidad) {
  for (Persona *persona : personas) {
    if (persona->get_nombre() == nombre && dynamic_cast<Profesor *>(persona)->get_especialidad() == especialidad) {
      return dynamic_cast<Profesor *>(persona);
    }
  }
  return nullptr; // El profesor no se encontró
}

Administrativo *Escuela::get_administrativo(string nombre, string departamento){
  for (Persona *persona : personas) {
    if (persona->get_nombre() == nombre && dynamic_cast<Administrativo *>(persona)->get_departamento() == departamento) {
      return dynamic_cast<Administrativo *>(persona);
    }
  }
  return nullptr; // El administrativo no se encontró
}

// Setters

void Escuela::set_nombre(string nombre) { this->nombre = nombre; }

void Escuela::set_direccion(string direccion) { this->direccion = direccion; }

void Escuela::set_telefono(string telefono) { this->telefono = telefono; }

// Metodos

void Escuela::show_personas() {
  for (Persona *persona : personas) {
    cout << persona->get_nombre() << "\n";
  }
}

void Escuela::agregar_alumno(string nombre, int edad, string telefono,
                             string direccion, string matricula) {
  Persona *persona = new Alumno(nombre, edad, telefono, direccion, matricula);

  personas.push_back(persona);
}

void Escuela::agregar_profesor(string nombre, int edad, string telefono,
                             string direccion, string especialidad) {
  Persona *persona = new Profesor(nombre, edad, telefono, direccion, especialidad);

  personas.push_back(persona);
}

void Escuela::agregar_administrativo(string nombre, int edad, string telefono,
                              string direccion, string departamento){
  Persona *persona = new Administrativo(nombre, edad, telefono, direccion, departamento);

  personas.push_back(persona);
}

#endif // Escuela_H_