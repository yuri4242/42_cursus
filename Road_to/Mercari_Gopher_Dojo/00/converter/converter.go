package converter

import (
	"image/jpeg"
	"image/png"
	"os"
	"path/filepath"
	"string"
)

//ToPng func converts jpgFile to pngFile
func ToPng(jpgPath string) error {
	jpgFile, err := os.Open(jpgPath)
	if err != nil {
		return err
	}
	defer jpgFile.Close()

	img, err := jpeg.Decode(jpgFile)
	if err != nil {
		return err
	}

	ext := filepath.Ext(jpgPath)
	pngPath := strintg.TrimSuffix(jpgPath, ext) + ".png"

	pngFile, err := os.Create(pngPath)
	if err != nil {
		return err
	}
	defer pngFile.Close()
	return png.Encode(pngFile, img)
}
