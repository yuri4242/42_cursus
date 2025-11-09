package converter

import (
	"fmt"
	"image/jpeg"
	"image/png"
	"os"
	"path/filepath"
	"strings"
)

// ToPng converts a JPG file specified by jpgFile to a PNG file.
// The new file will be created in the same directory with a .png extension.
func ToPng(jpgPath string) error {
	jpgFile, err := os.Open(jpgPath)
	if err != nil {
		return fmt.Errorf("failed to open %s: %w", jpgPath, err)
	}
	defer jpgFile.Close()

	img, err := jpeg.Decode(jpgFile)
	if err != nil {
		return fmt.Errorf("failed to decode %s (not a vaild JPG?): %w", jpgPath, err)
	}

	ext := filepath.Ext(jpgPath)
	pngPath := strings.TrimSuffix(jpgPath, ext) + ".png"

	pngFile, err := os.Create(pngPath)
	if err != nil {
		return fmt.Errorf("filed to create %s: %w", pngPath, err)
	}
	defer pngFile.Close()
	err = png.Encode(pngFile, img)
	if err != nil {
		return fmt.Errorf("filed to encode %s: %w", pngPath, err)
	}
	return nil
}
