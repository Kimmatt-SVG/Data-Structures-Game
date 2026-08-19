# Photography Portfolio

A beautiful, modern, and responsive photography portfolio website built with HTML, CSS, and JavaScript. Perfect for photographers, artists, and creatives looking to showcase their work online.

![Portfolio Preview](https://img.shields.io/badge/Status-Ready-brightgreen)

## Features

- **Modern Design**: Clean and professional interface with smooth animations
- **Fully Responsive**: Works seamlessly on desktop, tablet, and mobile devices
- **Portfolio Gallery**: Organized grid layout with category filtering
- **Interactive Lightbox**: Click any image to view it in full-screen mode with navigation
- **Category Filtering**: Filter portfolio items by Landscape, Portrait, Wildlife, or Urban
- **Smooth Scrolling**: Enhanced navigation experience with smooth scrolling
- **Contact Form**: Built-in contact form for client inquiries
- **Social Media Links**: Easy integration with Instagram, Twitter, and Facebook
- **SEO Friendly**: Semantic HTML structure optimized for search engines
- **GitHub Pages Ready**: Easy deployment to GitHub Pages

## Quick Start

### View Locally

1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/photography-portfolio.git
   cd photography-portfolio
   ```

2. Open `index.html` in your web browser, or use a local server:
   ```bash
   python -m http.server 8000
   ```
   Then visit `http://localhost:8000`

### Deploy to GitHub Pages

1. Go to your repository on GitHub
2. Click on **Settings**
3. Scroll down to **Pages** section
4. Under **Source**, select the branch you want to deploy (usually `main` or `master`)
5. Click **Save**
6. Your site will be published at `https://yourusername.github.io/repository-name/`

## Customization Guide

### Adding Your Photos

Replace the placeholder SVGs with your actual photographs:

1. Add your images to an `images` folder (create if it doesn't exist)
2. In `index.html`, replace the placeholder divs with `<img>` tags:

```html
<!-- Before -->
<div class="gallery-item" data-category="landscape">
    <div class="image-placeholder gallery-placeholder">
        <!-- SVG placeholder -->
    </div>
</div>

<!-- After -->
<div class="gallery-item" data-category="landscape">
    <img src="images/mountain-vista.jpg" alt="Mountain Vista">
</div>
```

3. Update the lightbox to display actual images in `script.js`

### Updating Personal Information

**Site Title and Branding:**
- Edit the `<title>` tag in `index.html`
- Change "PhotoFolio" in the navigation logo

**About Section:**
- Update the biography text in the About section
- Modify statistics (Projects, Awards, Years)

**Contact Information:**
- Update email: `contact@photofolio.com`
- Update phone: `+1 (555) 123-4567`
- Update location: `New York, NY`

**Social Media Links:**
- Replace `#` with your actual social media URLs in the footer

### Customizing Colors

Edit CSS variables in `styles.css`:

```css
:root {
    --primary-color: #2c3e50;      /* Main text and navbar */
    --secondary-color: #e74c3c;    /* Buttons and accents */
    --accent-color: #3498db;       /* Links and highlights */
    --text-color: #333;            /* Body text */
    --light-text: #777;            /* Secondary text */
    --bg-light: #f8f9fa;           /* Section backgrounds */
}
```

### Adding More Categories

1. Add a new filter button in `index.html`:
```html
<button class="filter-btn" data-filter="yourcategory">Your Category</button>
```

2. Add gallery items with the matching category:
```html
<div class="gallery-item" data-category="yourcategory">
    <!-- Your image here -->
</div>
```

### Customizing the Hero Section

Edit the hero section in `index.html`:
```html
<h1 class="hero-title">Your Name<br><span class="highlight">Your Tagline</span></h1>
<p class="hero-subtitle">Your Subtitle</p>
```

## Project Structure

```
photography-portfolio/
│
├── index.html          # Main HTML file
├── styles.css          # All styling and responsive design
├── script.js           # JavaScript for interactivity
├── README.md           # This file
└── images/             # Your photography images (create this folder)
```

## Browser Support

- Chrome (latest)
- Firefox (latest)
- Safari (latest)
- Edge (latest)
- Mobile browsers

## Technologies Used

- **HTML5**: Semantic markup
- **CSS3**: Modern styling with Flexbox and Grid
- **JavaScript (ES6+)**: Interactive features
- **Google Fonts**: Playfair Display and Poppins fonts

## Features Breakdown

### Responsive Navigation
- Hamburger menu on mobile devices
- Smooth scroll to sections
- Fixed header with shadow on scroll

### Portfolio Gallery
- CSS Grid layout
- Category filtering with smooth transitions
- Hover effects for better interactivity

### Lightbox
- Full-screen image viewing
- Keyboard navigation (Arrow keys, Escape)
- Previous/Next buttons
- Click outside to close

### Animations
- Fade-in effects on scroll
- Smooth transitions
- Counter animation for statistics

## Tips for Photographers

1. **Image Optimization**: Compress your images before uploading (use tools like TinyPNG or ImageOptim)
2. **Image Dimensions**: Recommended size: 1200-1500px on the longest side
3. **File Format**: Use JPEG for photographs, PNG for graphics with transparency
4. **Alt Text**: Always add descriptive alt text for accessibility and SEO
5. **Watermark**: Consider adding a subtle watermark to protect your work

## Performance Optimization

- Use lazy loading for images (add `loading="lazy"` to img tags)
- Compress images to reduce file size
- Minify CSS and JavaScript for production
- Enable caching through GitHub Pages

## License

This project is open source and available under the [MIT License](LICENSE).

## Support

If you have any questions or need help customizing your portfolio:
- Open an issue on GitHub
- Check the documentation
- Review the code comments

## Credits

Created with passion for photographers worldwide. Feel free to use, modify, and share!

---

**Happy Showcasing! 📸**
