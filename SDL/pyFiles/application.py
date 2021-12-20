import psutil
import os
import json
import xml.etree.ElementTree as ET
from zipfile import ZipFile


def file_info():
    print("Devices types, mounts, space info")
    space = psutil.disk_usage('/')
    print(f"Total space: {space.total / (2 ** 30)} GiB")
    print(f"Used space: {space.used / (2 ** 30)} GiB")
    print(f"Free space: {space.free / (2 ** 30)} GiB")

    dps = psutil.disk_partitions()
    for p in dps:
        space = psutil.disk_usage(p.mountpoint)
        print(f"Name: {p.device}")
        print(f"FS type: {p.fstype}")
        print(f"Mount point: {p.mountpoint}")
        print(f"Used space: {space.used / (2 ** 30)} GiB")


def file():
    print("File create, write, read, delete")
    filename = input("File name: ")
    text = input("File data: ")

    with open(filename, 'w+') as file:
        file.write(text + '\n')
    with open(filename, 'r') as file:
        print("File data: " + file.read())
    need_delete = input("Delete this file? ")
    if need_delete == "True":
        os.remove(filename)


def json_file(individual):
    print("Json create, write, read, delete")
    filename = "individual.json"
    with open(filename, 'w+') as file:
        json.dump(individual, file)
    with open(filename, 'r') as file:
        data = json.load(file)
    print(f"File data: {data}")
    need_delete = input("Delete this file? ")
    if need_delete == "True":
        os.remove(filename)


def xml_file(individual):
    print("Xml create, write, read, delete")
    filename = "individual.xml"

    p = ET.Element('parent')
    i = ET.SubElement(p, 'individual')
    ET.SubElement(i, "first_name").text = individual['first_name']
    ET.SubElement(i, "last_name").text = individual['last_name']
    tree = ET.ElementTree(p)
    tree.write(filename)

    tree = ET.parse(filename)
    root = tree.getroot()
    print("File data: ")
    for element in root:
        for sub_element in element:
            print(sub_element.tag, ": ", sub_element.text)
    need_delete = input("Delete this file? ")
    if need_delete == "True":
        os.remove(filename)


def zip_file():
    filename = "application.py"
    zip_name = "application.zip"
    with ZipFile(zip_name, "w") as zip:
        zip.write(filename)
    with ZipFile(zip_name, 'r') as zip:
        zip.extractall('extracted')
    print("Zip extracted: ")
    with open('extracted/' + filename) as file:
        print("File data: " + file.read())


if __name__ == '__main__':
    file_info()
    print('=====================================')

    file()
    print('=====================================')

    first_name = input("Type first name: ")
    last_name = input("Type last name: ")
    individual = {
        'first_name': first_name,
        'last_name': last_name
    }

    json_file(individual)
    print('=====================================')

    xml_file(individual)
    print('=====================================')

    zip_file()
    print('=====================================')