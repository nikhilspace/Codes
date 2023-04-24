import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt
from tensorflow import datasets, layers, models



(training_images,training_label),(testing_images,testing_label) = datasets.cifar10.load_data()
training_images, testing_images = training_images / 255, testing_images / 255


class_names = ['plane','car','horse','deer','dog','cat','truck','frog','ship','bird']

for i in range(16):
    plt.subplot(4,4,i+1)
    plt.xticks([])
    plt.yticks([])
    plt.imshow(training_images[i], cmap=plt.cm.binary)
    plt.xlabel(class_names[training_label[i][0]])
    plt.show()


training_images = training_images[:20000]
training_label = training_label[:20000]
testing_images = testing_images[:4000]
testing_label = testing_label[:4000]


model = models.Sequential()
model.add(layers.Conv2D(32, (3,3), activation = 'relu', input_shape=(32,32,3)))
model.add(layers.MaxPooling2D((2,2)))
model.add(layers.Conv2D(64, (3,3), activation = 'relu'))
model.add(layers.MaxPooling2D((2,2)))
model.add(layers.Conv2D(64, (3,3), activation = 'relu'))
model.add(layers.Flatten())
model.add(layers.Dense(64, activation = 'relu'))
model.add(layers.Dense(10, activation = 'softmax'))


model.compile(optimizer = 'adam', loss = 'sparse_categorical_crossentropy', matrics=['accuracy'])
model.fit(training_images,training_label, epochs=10,validation_data=(training_images,training_label))



