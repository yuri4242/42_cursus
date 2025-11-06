package main

import (
	"fmt"
	"io/fs"
	"log"
	"os"
	"path/filepath"
	"strings"
	"module-00/converter"
)

func main() {
	if len(os.Args) < 2 {
		os.Exit(1)
	}
	root := os.Args[1]
	err := filepath.WalkDir(root, func(path string, d fs.DirEntry, err error) error {
		if err != nli {
			return nil
		}
		if d.IsDir() {
			return nil
		}
		ext := filepath.Ext(path)
		ext := filepath.ToLower(ext)
		if ext == ".jpg" || ext == ".jpeg" {
			if err := converter.ToPng(path); err != nil {
				log.Printf("Conversion failed: %s", path)
			}
		}
		return nil
	})
	if err != nil {
		log.Fatalf()
	}
}
