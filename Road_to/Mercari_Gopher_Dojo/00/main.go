package main

import (
	"errors"
	"fmt"
	"io/fs"
	"log"
	"os"
	"path/filepath"
	"strings"
	"module-00/converter"
)

func main() {
	if len(os.Args) != 2 {
		fmt.Fprintln(os.Stderr, "error: invalid argument")
		os.Exit(1)
	}
	root := os.Args[1]
	err := filepath.WalkDir(root, func(path string, d fs.DirEntry, err error) error {
		if err != nil {
			return err
		}
		if d.IsDir() {
			return nil
		}
		ext := filepath.Ext(path)
		ext = strings.ToLower(ext)
		if ext == ".jpg" || ext == ".jpeg" {
			if err := converter.ToPng(path); err != nil {
				log.Printf("Conversion failed: %s, %v", path, err)
			}
			return nil
		}
		return fmt.Errorf("%s is not a valid file", path)
	})
	if err != nil {
		var pathError *fs.PathError
		if errors.As(err, &pathError) {
			fmt.Fprintf(os.Stderr, "error: %s: %v\n", pathError.Path, pathError.Err)
		} else {
			fmt.Fprintf(os.Stderr, "error: %v\n", err)
		}
		os.Exit(1)
	}
}
