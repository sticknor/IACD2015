from PIL import Image, ImageFilter
import sys
import random 

def changeBaseBackground(red, green, blue):
    BGpixels = new_im.load()
    for x in range(0, new_im.size[0]):
        for y in range(0, new_im.size[1]):
            BGpixels[x, y] = (red, green, blue, 255)

new_im = Image.new('RGBA', (1000, 1000))
changeBaseBackground(255, 255, 255)

def removeWhiteBackground(pixels, size):
    for x in range(0, size[0]):
        for y in range(0, size[1]):
            thisPixel = pixels[x, y]
            # if value of pixel is close to white, make it transparent
            if thisPixel[0] >= 225 and thisPixel[1] >= 225 and thisPixel[2] >= 225:
                pixels[x, y] = (0, 0, 0, 0)


def getAverageColor(pixels, size):
    red = 0;
    green = 0;
    blue = 0;
    pixelCount = 0;
    for x in range(0, size[0]):
        for y in range(0, size[1]):
            thisPixel = pixels[x, y]
            if thisPixel[3] != 0:
                red += thisPixel[0]
                green += thisPixel[1]
                blue += thisPixel[2]
                pixelCount += 1;
    return [red/pixelCount, green/pixelCount, blue/pixelCount]



def processImage(path, multiplier, x, y, newWidth, newHeight):

    try:
        #open image
        print path
        original = Image.open(path)
        #original.format, original.size, original.mode)
        #convert into RGBA
        im = original.convert('RGBA')
        #load pixel array and mask out white background
        pixels = im.load()
        removeWhiteBackground(pixels, original.size)
        width = im.size[0]
        height = im.size[1]
        if multiplier == 1:
            bgColor = getAverageColor(pixels, original.size)
            changeBaseBackground(bgColor[0], bgColor[1], bgColor[2])
            if width > height:
                toAdd = 1000-height
                newHeight = int((1+(toAdd/float(height)))*height)+10
                newWidth = int((1+(toAdd/float(height)))*width)+10
            else:
                toAdd = 1000-width
                newHeight = int((1+(toAdd/float(width)))*height)+10
                newWidth = int((1+(toAdd/float(width)))*width)+10
        else:
            factor = multiplier #+random.random()- random.random()
            newWidth = int(width*factor)
            newHeight = int(height*factor)

        img_resized = im.resize((newWidth, newHeight), Image.ANTIALIAS)
        img_resized.save(path)
        new_im.paste(Image.open(path), (x, y), img_resized)
    except:
        print "Unable to load/convert image"

def makeCollage(folder):
    processImage(folder+"/1.png", 1, 0, 0, 0, 0)
    processImage(folder+"/2.png", random.random(), int(random.random()*200), int(random.random()*300), 0, 0)
    processImage(folder+"/3.png", random.random(), int(random.random()*100), int(random.random()*100), 0, 0)
    processImage(folder+"/4.png", random.random(), int(random.random()*200), int(random.random()*300), 0, 0)
    processImage(folder+"/5.png", random.random(), int(random.random()*50), int(random.random()*40), 0, 0)
    processImage(folder+"/6.png", random.random(), int(random.random()*600), int(random.random()*400), 0, 0)

    new_im.save(folder+"/collage.png")


makeCollage(sys.argv[1])


