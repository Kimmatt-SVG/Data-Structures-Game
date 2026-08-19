document.addEventListener('DOMContentLoaded', () => {
    const hamburger = document.querySelector('.hamburger');
    const navMenu = document.querySelector('.nav-menu');
    const navLinks = document.querySelectorAll('.nav-link');
    const filterButtons = document.querySelectorAll('.filter-btn');
    const galleryItems = document.querySelectorAll('.gallery-item');
    const lightbox = document.getElementById('lightbox');
    const closeLightbox = document.querySelector('.close-lightbox');
    const lightboxPrev = document.querySelector('.lightbox-prev');
    const lightboxNext = document.querySelector('.lightbox-next');
    const contactForm = document.querySelector('.contact-form');

    let currentImageIndex = 0;
    let currentFilter = 'all';

    hamburger.addEventListener('click', () => {
        navMenu.classList.toggle('active');
        
        const spans = hamburger.querySelectorAll('span');
        if (navMenu.classList.contains('active')) {
            spans[0].style.transform = 'rotate(45deg) translate(5px, 5px)';
            spans[1].style.opacity = '0';
            spans[2].style.transform = 'rotate(-45deg) translate(7px, -6px)';
        } else {
            spans[0].style.transform = 'none';
            spans[1].style.opacity = '1';
            spans[2].style.transform = 'none';
        }
    });

    navLinks.forEach(link => {
        link.addEventListener('click', () => {
            navMenu.classList.remove('active');
            const spans = hamburger.querySelectorAll('span');
            spans[0].style.transform = 'none';
            spans[1].style.opacity = '1';
            spans[2].style.transform = 'none';
        });
    });

    filterButtons.forEach(button => {
        button.addEventListener('click', () => {
            filterButtons.forEach(btn => btn.classList.remove('active'));
            button.classList.add('active');
            
            const filterValue = button.getAttribute('data-filter');
            currentFilter = filterValue;
            
            galleryItems.forEach((item, index) => {
                const category = item.getAttribute('data-category');
                
                if (filterValue === 'all' || category === filterValue) {
                    item.style.display = 'block';
                    setTimeout(() => {
                        item.style.opacity = '1';
                        item.style.transform = 'translateY(0)';
                    }, index * 60);
                } else {
                    item.style.opacity = '0';
                    item.style.transform = 'translateY(30px)';
                    setTimeout(() => {
                        item.style.display = 'none';
                    }, 400);
                }
            });
        });
    });

    galleryItems.forEach((item, index) => {
        item.addEventListener('click', () => {
            const visibleItems = Array.from(galleryItems).filter(i => {
                const category = i.getAttribute('data-category');
                return currentFilter === 'all' || category === currentFilter;
            });
            currentImageIndex = visibleItems.indexOf(item);
            openLightbox();
        });
    });

    function openLightbox() {
        lightbox.classList.add('active');
        document.body.style.overflow = 'hidden';
        updateLightboxContent();
    }

    function closeLightboxFunc() {
        lightbox.classList.remove('active');
        document.body.style.overflow = 'auto';
    }

    function updateLightboxContent() {
        const visibleItems = Array.from(galleryItems).filter(item => {
            const category = item.getAttribute('data-category');
            return currentFilter === 'all' || category === currentFilter;
        });
        
        if (visibleItems.length > 0 && currentImageIndex < visibleItems.length) {
            const currentItem = visibleItems[currentImageIndex];
            const placeholder = currentItem.querySelector('.gallery-placeholder');
            const title = placeholder.querySelector('span').textContent;
            
            const lightboxContent = lightbox.querySelector('.lightbox-content');
            const lightboxPlaceholder = lightboxContent.querySelector('.lightbox-placeholder');
            
            const svg = placeholder.querySelector('svg').cloneNode(true);
            lightboxPlaceholder.innerHTML = '';
            lightboxPlaceholder.appendChild(svg);
            
            const titleSpan = document.createElement('span');
            titleSpan.textContent = title;
            titleSpan.style.position = 'absolute';
            titleSpan.style.bottom = '40px';
            titleSpan.style.left = '50%';
            titleSpan.style.transform = 'translateX(-50%)';
            titleSpan.style.fontSize = '1.8rem';
            titleSpan.style.fontWeight = '300';
            titleSpan.style.fontFamily = "'Playfair Display', serif";
            titleSpan.style.letterSpacing = '0.02em';
            lightboxPlaceholder.appendChild(titleSpan);
        }
    }

    function showPrevImage() {
        const visibleItems = Array.from(galleryItems).filter(item => {
            const category = item.getAttribute('data-category');
            return currentFilter === 'all' || category === currentFilter;
        });
        
        currentImageIndex = (currentImageIndex - 1 + visibleItems.length) % visibleItems.length;
        updateLightboxContent();
    }

    function showNextImage() {
        const visibleItems = Array.from(galleryItems).filter(item => {
            const category = item.getAttribute('data-category');
            return currentFilter === 'all' || category === currentFilter;
        });
        
        currentImageIndex = (currentImageIndex + 1) % visibleItems.length;
        updateLightboxContent();
    }

    closeLightbox.addEventListener('click', closeLightboxFunc);
    
    lightbox.addEventListener('click', (e) => {
        if (e.target === lightbox) {
            closeLightboxFunc();
        }
    });

    lightboxPrev.addEventListener('click', (e) => {
        e.stopPropagation();
        showPrevImage();
    });

    lightboxNext.addEventListener('click', (e) => {
        e.stopPropagation();
        showNextImage();
    });

    document.addEventListener('keydown', (e) => {
        if (lightbox.classList.contains('active')) {
            if (e.key === 'Escape') {
                closeLightboxFunc();
            } else if (e.key === 'ArrowLeft') {
                showPrevImage();
            } else if (e.key === 'ArrowRight') {
                showNextImage();
            }
        }
    });

    contactForm.addEventListener('submit', (e) => {
        e.preventDefault();
        
        const name = e.target[0].value;
        const email = e.target[1].value;
        
        alert(`Thank you for reaching out, ${name}. We'll respond to ${email} shortly.`);
        contactForm.reset();
    });

    const observerOptions = {
        threshold: 0.15,
        rootMargin: '0px 0px -80px 0px'
    };

    const observer = new IntersectionObserver((entries) => {
        entries.forEach(entry => {
            if (entry.isIntersecting) {
                entry.target.style.opacity = '1';
                entry.target.style.transform = 'translateY(0)';
            }
        });
    }, observerOptions);

    document.querySelectorAll('.gallery-item, .about-content, .contact-content').forEach(el => {
        el.style.opacity = '0';
        el.style.transform = 'translateY(40px)';
        el.style.transition = 'opacity 0.8s cubic-bezier(0.4, 0, 0.2, 1), transform 0.8s cubic-bezier(0.4, 0, 0.2, 1)';
        observer.observe(el);
    });

    window.addEventListener('scroll', () => {
        const navbar = document.querySelector('.navbar');
        if (window.scrollY > 100) {
            navbar.style.background = 'rgba(255, 255, 255, 0.98)';
            navbar.style.borderBottomColor = 'rgba(0, 0, 0, 0.08)';
        } else {
            navbar.style.background = 'rgba(255, 255, 255, 0.95)';
            navbar.style.borderBottomColor = 'var(--border-color)';
        }
    });

    const stats = document.querySelectorAll('.stat h3');
    let animated = false;

    function animateStats() {
        if (animated) return;
        
        stats.forEach(stat => {
            const target = parseInt(stat.textContent);
            let current = 0;
            const increment = target / 60;
            const timer = setInterval(() => {
                current += increment;
                if (current >= target) {
                    stat.textContent = target;
                    clearInterval(timer);
                } else {
                    stat.textContent = Math.floor(current);
                }
            }, 25);
        });
        
        animated = true;
    }

    const aboutSection = document.querySelector('.about');
    const aboutObserver = new IntersectionObserver((entries) => {
        entries.forEach(entry => {
            if (entry.isIntersecting) {
                animateStats();
            }
        });
    }, { threshold: 0.4 });

    if (aboutSection) {
        aboutObserver.observe(aboutSection);
    }

    galleryItems.forEach(item => {
        item.style.transition = 'all 0.6s cubic-bezier(0.4, 0, 0.2, 1)';
    });
});
